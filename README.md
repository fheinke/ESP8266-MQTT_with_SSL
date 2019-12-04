# ESP8266-MQTT_with_SSL
Example Sketch how to connect your ESP8266 with an SSL Secured MQTT Broker.

### Description
This Sketch is just an example, to show you how to set up a secure MQTT Connection to your own MQTT Broker. My Test Broker is secured with an User and Password plus SSL Certificate.

You'll need to change the Variables first.

To get the Fingerprint of your MQTT SSL Certificate, you can use following command in a Linux shell with <MQTTBroker> as your Broker:

```console
FHeinke@GitHub:~$ echo | openssl s_client -connect <MQTTBroker>:8883 | openssl x509 -fingerprint -noout
SHA1 Fingerprint=00:11:22:33:44:55:66:77:88:99:00:AA:BB:CC:DD:EE:FF:00:11:22
```

#### Device for my Test:
ESP8266 D1 Mini

#### License:
WTFPL (Do What The Fuck You Want To Public License)
