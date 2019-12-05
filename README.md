# ESP8266-MQTT_with_SSL

### Description
This sketch is intended only as an example to show how to connect an ESP8266 microcontroller to an SSL, user and password protected MQTT broker.

First of all, all variables in the sketch must be adapted to your own needs.

To get the SSL fingerprint of the broker, just enter the following command on a Linux shell. Please replace <MQTTBroker> with your Internet hostname.

```console
FHeinke@GitHub:~$ echo | openssl s_client -connect <MQTTBroker>:8883 | openssl x509 -fingerprint -noout
SHA1 Fingerprint=00:11:22:33:44:55:66:77:88:99:00:AA:BB:CC:DD:EE:FF:00:11:22
```

#### Device for my Test:
ESP8266 D1 Mini


## License:
WTFPL (Do What The Fuck You Want To Public License)
