void verifyFingerprint()
{
  // If Client is already connected, the Fingerprint must not be tested
  if (client.connected() || espClient.connected()) return;

  Serial.print("Checking TLS @ ");
  Serial.print(mqtt_server);
  Serial.print("...");
  Serial.println("");

  // Client has to be connected to the Broker
  if (!espClient.connect(mqtt_server, mqtt_port)) {
    Serial.println("Connection failed. Rebooting.");
    Serial.flush();
    ESP.restart();
  }

  // Verify SSL Fingerprint of the Broker
  if (espClient.verify(mqtt_fprint, mqtt_server)) {
    Serial.print("Connection secure -> .");
  } else {
    Serial.println("Connection insecure! Rebooting.");
    Serial.flush();
    ESP.restart();
  }

  espClient.stop();

  delay(100);
}
