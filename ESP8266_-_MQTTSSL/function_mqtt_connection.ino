// Connect ESP with the MQTT Broker
void mqtt_connect()
{
  // Set SSL Fingerprint
  espClient.setFingerprint(mqtt_fprint);

  // Set MQTT Server
  client.setServer(mqtt_server, mqtt_port);

  // While Loop as long as the Client is not connected to the Broker
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");

    // MQTT verify Fingerprint Function
    verifyFingerprint();
    
    if (client.connect(WiFi.macAddress().c_str(), mqtt_user, mqtt_password))
    {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}



// Check MQTT Connection
void mqtt_check_connection()
{
  // While Loop as long as the Client is not connected to the Broker
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");

    // MQTT verify Fingerprint Function
    verifyFingerprint();
    if (client.connect(WiFi.macAddress().c_str(), mqtt_user, mqtt_password))
    {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
