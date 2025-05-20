# ExemplosPVB

Para executar estes exemplos você precisa do [pvbrowser®](https://pvbrowser.de).
Para facilitar a configuração de um setup completo para trabalhar com o pvbrowser em uma distribuição Linux baseada no Ubuntu 24.04, foi criado um script com este propósito:

```
curl -Ls jjmg.eng.br/install/setup-full.sh | sudo bash
```

Uma explicação detalhada sobre a instalação com este script está em 

```
https://jjmg.eng.br/software.html
```

Os seguintes exemplos estão disponíveis:

- cpushover : modificação de um repositório com o mesmo nome para que funcione como um daemon de notificações para o pvbrowser com o Pushover. Inclui um exemplo para fazer o mesmo com NTFY;
- mqtt : demonstração de MQTT no pvbrowser com o uso de mosquitto_pub e mosquito_sub;
- recipe : exemplo simples de como criar receitas no pvbrowser;
- pvDataProc : implementação de um programa processador de dados para tratar, agrupar e armazenar dados lidos de daemons de comunicação e enviá-los ao pvserver numa estrutura de dados via memória compartilhada.
- pvWavePlot : exemplo de como exibir gráficos criados com a matplotlib por um programa em Python rodando em segundo plano 
