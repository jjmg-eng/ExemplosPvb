GEMINI AI no pvbrowser
======================
Exemplo de conexão entre a inteligência artificial do Google (Gemini) com o pvbrowser®


https://github.com/user-attachments/assets/204fafc9-bb56-40db-ae19-8be9e6291404

Para executar este exemplo você vai precisar compilar o programa gemini_client.
Este programa usa a biblioteca nlohmann/json para analisar a resposta da API.
Você vai precisar do CMake e da biblioteca cURL. Instale pelo terminal com:
```
sudo apt install libcurl4-openssl-dev cmake
```
Entre na pasta gemini_cpp_client, crie a pasta build e seguindo as seguintes instruções, compile o programa gemini_client:
```
mkdir build
cd build
cmake ..
cmake --build .
mv gemini_client ../..
cd ../..
```
Se não houve erro, agora vc deve estar dentro da pasta do projeto (pvGemini). Compile os dois daemons de comunicação:
```
g++ mbx_in.cpp -o mbx_in -lrllib
g++ mbx_out.cpp -o mbx_out -lrllib
```
Compile o pvserver:
```
qmake
make
```
Agora devem existir 4 programas executáveis :
- pvs : aplicação do pvbrowser (pvserver);
- mbx_in : daemon de comunicação para enviar prompts para a Gemini;
- mbx_out : daemon de comunicação para enviar as respostas da API para o pvserver;
- gemini_client : cliente para terminal para a AI Gemini do Google.

Agora será preciso obter uma chave de API no Google AI Studio: https://aistudio.google.com/
Copie sua chave de API e crie uma varíavel de ambiente em ~/.bashrc
Insira esta linha no final do arquivo:
```
export GEMINI_API_KEY="SUA_CHAVE_AQUI"
```
Cole a chave de API que você copiou no lugar de "SUA CHAVE AQUI". Salve o arquivo e volte ao terminal. Digite este comando para efetivar a nova variável de ambiente:
```
source ~/.bashrc
```
Agora vc pode testar se consegue usar a Gemini pelo terminal usando o cliente em "verbose mode"
```
./gemini_client -v
```
Se tudo funcionou, podemos rodar o projeto completo. Para isso rode o cliente com os daemons de conexão com o pvbrowser:
```
./mbx_in | ./gemini_client | ./mbx_out
```
Em outro terminal, rode o pvs:
```
./pvs -gui
```
Tente reproduzir o que aparece no vídeo.

