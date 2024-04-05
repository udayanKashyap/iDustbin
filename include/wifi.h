#include <ESP8266WiFi.h>


#define WIFI_SSID "OnePlus Nord CE 2 "
#define WIFI_PASSWORD "jilljill"

// Initialize WiFi
void initWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  Serial.println();
}

