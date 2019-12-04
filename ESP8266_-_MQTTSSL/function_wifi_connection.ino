// Connect ESP with the WiFi Network
void wifi_connect()
{
  // Counter for max. Retries
  int counter = 0;

  Serial.print("Connecting to Wifi ");
  Serial.println(wifi_ssid);

  // Disconnect from WiFi to set new WiFi Connection
  WiFi.disconnect(true);
  // Set the WiFi Mode to STA
  WiFi.mode(WIFI_STA);

  // Try Connecting to the WiFi
  WiFi.begin(wifi_ssid, wifi_password);
  delay(100);

  // While Client is not connected to the WiFi
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
    counter++;
    // If no Connection possible after 30 Seconds, restart ESP
    if (counter >= 60) {
      ESP.restart();
    }
  }

  String wifi_ip = WiFi.localIP().toString();
  Serial.println();
  Serial.println("Connected");
  Serial.println("IP Address: " + wifi_ip);
}



// Check WiFi Connection
void wifi_reconnect()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    // Counter for max. Retries
    int counter = 0;

    Serial.println("");
    Serial.println("Lost WiFi Connection");
    Serial.println("Reconnecting to SSID: " + (String)wifi_ssid);

    // Disconnect from WiFi to set new WiFi Connection
    WiFi.disconnect(true);
    // Set the WiFi Mode to STA
    WiFi.mode(WIFI_STA);

    // Try Connecting to the WiFi
    WiFi.begin(wifi_ssid, wifi_password);
    delay(100);

    // While Client is not connected to the WiFi
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(500);
      counter++;
      // If no Connection possible after 30 Seconds, restart ESP
      if (counter >= 60) {
        ESP.restart();
      }
    }

    String wifi_ip = WiFi.localIP().toString();
    Serial.println();
    Serial.println("Connected");
    Serial.println("IP Address: " + wifi_ip);
  }
}
