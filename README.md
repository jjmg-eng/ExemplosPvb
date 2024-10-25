# ExemplosPVB

Para executar estes exemplos você precisa do [pvbrowser®](https://pvbrowser.de).
Para facilitar a configuração de um setup completo para trabalhar com o pvbrowser em uma distribuição Linux baseada no Ubuntu 24.04, foi criado um script com este propósito:

```
curl -s jjmg.eng.br/install/setup-full.sh | sudo bash
```
Os seguintes exemplos estão disponíveis:

- cpushover : modificação de um repositório com o mesmo nome para que funcione como um daemon de notificações para o pvbrowser com o Pushover. Inclui um exemplo para fazer o mesmo com NTFY;
- mqtt : demonstração de MQTT no pvbrowser com o uso de mosquitto_pub e mosquito_sub
