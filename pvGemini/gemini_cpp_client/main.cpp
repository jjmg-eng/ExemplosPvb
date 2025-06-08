#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string_view>

// Variável global para controlar o modo verbose
bool is_verbose = false;

// Funções de callback para cURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string get_api_key() {
    // Tenta carregar de variável de ambiente primeiro (recomendado)
    const char* api_key_env = std::getenv("GEMINI_API_KEY");
    if (api_key_env) {
        return std::string(api_key_env);
    }

    // Se não encontrar, tenta carregar de um arquivo (menos seguro para produção)
    std::ifstream api_key_file("api_key.txt");
    if (api_key_file.is_open()) {
        std::string key;
        std::getline(api_key_file, key);
        api_key_file.close();
        return key;
    }

    return ""; // Retorna vazio se não encontrar
}

std::string send_prompt_to_gemini(const std::string& prompt, const std::string& api_key) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=" + api_key;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        nlohmann::json request_body;
        request_body["contents"][0]["parts"][0]["text"] = prompt;
        
        std::string json_payload = request_body.dump();
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_payload.c_str());

        // Apenas imprime se o modo verbose estiver ativo
        if (is_verbose) {
            std::cout << "Enviando para a API: " << json_payload << std::endl;
        }

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() falhou: " << curl_easy_strerror(res) << std::endl;
            readBuffer = "";
        }
        
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return readBuffer;
}

// A função main agora recebe argumentos
int main(int argc, char* argv[]) {
    // Analisa os argumentos da linha de comando
    for (int i = 1; i < argc; ++i) {
        std::string_view arg = argv[i];
        if (arg == "-v" || arg == "--verbose") {
            is_verbose = true;
        }
    }

    std::string api_key = get_api_key();
    if (api_key.empty()) {
        std::cerr << "Erro: Chave de API não encontrada. Por favor, defina a variável de ambiente GEMINI_API_KEY ou crie um arquivo api_key.txt." << std::endl;
        return 1;
    }

    // Apenas imprime se o modo verbose estiver ativo
    if (is_verbose) {
        std::cout << "Bem-vindo ao meu programa de interação com IA (C++)!" << std::endl;
    }

    while (true) {
        // AQUI: Mensagem do prompt só aparece em modo verbose
        if (is_verbose) {
            std::cout << "\nDigite seu prompt (ou 'sair' para encerrar): ";
        }
        std::string user_prompt;
        std::getline(std::cin, user_prompt);

        if (user_prompt == "sair") {
            // Apenas imprime se o modo verbose estiver ativo
            if (is_verbose) {
                std::cout << "Encerrando o programa. Até mais!" << std::endl;
            }
            break;
        }

        // Apenas imprime se o modo verbose estiver ativo
        if (is_verbose) {
            std::cout << "\nAguarde a resposta da IA..." << std::endl;
        }
        
        std::string ia_response_json = send_prompt_to_gemini(user_prompt, api_key);

        if (!ia_response_json.empty()) {
            try {
                nlohmann::json response_json = nlohmann::json::parse(ia_response_json);
                
                if (response_json.contains("candidates") && !response_json["candidates"].empty() &&
                    response_json["candidates"][0].contains("content") &&
                    response_json["candidates"][0]["content"].contains("parts") &&
                    !response_json["candidates"][0]["content"]["parts"].empty() &&
                    response_json["candidates"][0]["content"]["parts"][0].contains("text")) {
                    
                    std::string ia_text_response = response_json["candidates"][0]["content"]["parts"][0]["text"].get<std::string>();
                    
                    // Imprime a resposta da IA SEMPRE, independentemente do verbose mode
                    std::cout << ia_text_response << std::endl;
                    
                } else {
                    std::cerr << "Erro: Não foi possível extrair o texto da resposta JSON." << std::endl;
                    // Imprime a resposta completa do JSON de erro apenas em modo verbose
                    if (is_verbose) {
                       std::cerr << "Resposta completa: " << ia_response_json << std::endl;
                    }
                }
            } catch (const nlohmann::json::parse_error& e) {
                std::cerr << "Erro ao parsear JSON: " << e.what() << std::endl;
                // Imprime a resposta bruta apenas em modo verbose
                if (is_verbose) {
                    std::cerr << "Resposta bruta: " << ia_response_json << std::endl;
                }
            }
        } else {
            std::cerr << "Não foi possível obter uma resposta da IA." << std::endl;
        }
    }

    return 0;
}
