#include <ESP8266WiFi.h>
#include <WiFiManager.h>

#define WIFI_SSID "OnePlus Nord CE 2 "
#define WIFI_PASSWORD "jilljill"

WiFiManager wifimanager;

// Initialize WiFi
void initWiFi() {
  wifimanager.autoConnect("ESP");
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println(WiFi.localIP());
  Serial.println();
}

void createAP(){
  WiFi.disconnect(1);
  Serial.println("Entering Config Mode");

  IPAddress localIP(10,0,0,1), gateway(10,0,0,1), subnet(255,255,255,0);
  wifimanager.setAPStaticIPConfig(localIP, gateway, subnet);

  wifimanager.startConfigPortal("ESP");
  return;
}
