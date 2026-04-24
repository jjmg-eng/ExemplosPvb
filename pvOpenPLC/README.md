# Integração OpenPLC e pvbrowser (Modbus TCP)

Este repositório contém um exemplo prático de integração entre o **OpenPLC** e o sistema SCADA **pvbrowser**. O objetivo é demonstrar o controle e a supervisão de uma lógica industrial utilizando exclusivamente ferramentas de software livre.

## 🚀 Visão Geral

O projeto consiste em um sistema de contagem onde a lógica de controle reside no OpenPLC e a interface de operação (IHM) é executada no pvbrowser. A comunicação entre os dois sistemas é realizada através do protocolo **Modbus TCP**.

### Funcionalidades:
* **Controle Bidirecional:** Botões na IHM para incrementar e decrementar o contador no PLC.
* **Monitoramento em Tempo Real:** Visualização do valor do contador através de indicadores analógicos e numéricos.
* **Lógica Industrial:** Uso de Blocos de Função (FBD) e Osciladores para geração de pulsos.

## 📁 Estrutura da Pasta `pvOpenPLC`

Diferente de estruturas separadas, este projeto mantém os arquivos integrados:

* **Arquivos do pvbrowser:** Códigos-fonte C++, máscaras da IHM e arquivos de projeto.
* **Projeto OpenPLC:** O programa escrito em **FBD** (Diagrama de Blocos) encontra-se na pasta `pvbOpenPLC`.

## 🛠️ Requisitos

* **OpenPLC** instalado (disponível em [autonomylogic.com](https://autonomylogic.com)).
* **pvbrowser** instalado (bibliotecas em `/opt/pvb`).
* Compilador `g++` e utilitário `make`.

## ⚙️ Configuração e Execução

### 1. Preparação do OpenPLC
1. Abra o **OpenPLC Editor** e carregue o projeto que está na pasta `pvbOpenPLC`.
2. O programa utiliza um oscilador para o contador.
3. Certifique-se de que o *Runtime* está executando e com o servidor Modbus TCP ativo.

### 2. Compilação do pvbrowser
Você pode utilizar o **pvdevelop** para compilar o projeto ou realizar os passos via terminal na pasta do projeto:

**Compilar o Servidor (pvs):**

```
make
```

**Compilar o Daemon de Comunicação Modbus:**

```
g++ modbusdaemon.cpp -o modbusdaemon -I /opt/pvb/rllib/lib/ -lrllib
```

### 3. Execução
1. Inicie o **modbusdaemon** para estabelecer o link com o OpenPLC.
2. Inicie o servidor do projeto: `./pvs`.
3. Lance o cliente: `pvbrowser localhost` (ou o IP correspondente).

## 📺 Demonstração em Vídeo

Confira a explicação detalhada, os procedimentos de compilação via terminal/pvdevelop e a animação da lógica em tempo real:
https://youtu.be/WWn3su62S2g?si=ZqeRSfM-zZJDS5oj

