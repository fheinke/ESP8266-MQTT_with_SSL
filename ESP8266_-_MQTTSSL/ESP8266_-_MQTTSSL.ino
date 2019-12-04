///////////////////////////////////////////////////////////////////////////////////////////////////
// 2019-12-04 Felix Heinke v0.1.0
//
// This Sketch is just for example, to show you how to set up a secure MQTT Connection
// to your own MQTT Broker. This Broker is secured with an User and Password plus SSL Certificate.
//
// You need to change the Variables with your values.
// To get the Fingerprint of your MQTT SSL Certificate, you can use following command
// in a Linux shell with <MQTTBroker> as your Broker:
// $ echo | openssl s_client -connect <MQTTBroker>:8883 | openssl x509 -fingerprint -noout
//
//  Device for my Test:
//  ESP8266 D1 Mini
//
//  License:
//  WTFPL (Do What The Fuck You Want To Public License)
//
///////////////////////////////////////// Initializing ////////////////////////////////////////////
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <PubSubClient.h>



// You may have to change the Values of those Variables
//////////////////////////////////////////////////////////////////////////////////////
// Wifi Network information
const char* wifi_ssid = "<SSID>";
const char* wifi_password = "<PASSWORD>";

// MQTT Settings
const char* mqtt_server = "<example.org>";
const unsigned int mqtt_port = 8883;
const char* mqtt_user = "<USER>";
const char* mqtt_password = "<PASSWORD>";
const char* mqtt_topic = "/ESP8266/topic";

// echo | openssl s_client -connect <MQTTBroker>:8883 | openssl x509 -fingerprint -noout
const char* mqtt_fprint = "AA:BB:CC:DD:EE:FF:00:11:22:33:44:55:66:77:88:99:AA:BB:CC:DD";
//////////////////////////////////////////////////////////////////////////////////////



WiFiClientSecure espClient;
PubSubClient client(espClient);

// For Uptime Example
unsigned long runningTime;



/////////////////////////////////////////// Setup ///////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  Serial.println();

  // WiFi Connection Function
  wifi_connect();

  // MQTT Connection Function
  mqtt_connect();

  Serial.println("========================== Start Loop ==========================");
  Serial.println();
  delay(100);
}



/////////////////////////////////////////// Loop ///////////////////////////////////////////
void loop() {
  // Check WiFi connection
  wifi_reconnect();

  // Check MQTT connection
  mqtt_check_connection();
  client.loop();

  // Example Message to Broker
  runningTime = millis();
  String message = "{\"Reason\": \"Test\", \"Uptime\": \"" + (String)runningTime + "\"}";

  // Send Message
  client.publish(mqtt_topic, String(message).c_str(), true);
  Serial.println((String)message);

  // Delay for 10 Second
  delay(10000);
}
