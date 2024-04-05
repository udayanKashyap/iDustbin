#include <Arduino.h>
#include <Wire.h>

#include "firebase.h"
#include "wifi.h"
#include "ultrasonic.cpp"

String distPath;

void blinkLedOnce();

// Timer variables
unsigned long sendDataPrevMillis = 0;
unsigned long timerDelay = 1000;


void setup(){
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  blinkLedOnce();

  pinMode(D3, INPUT_PULLUP);

  //init sensor
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  initWiFi();
  // Assign the api key (required)
  config.api_key = API_KEY;

  // Assign the user sign in credentials
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  // Assign the RTDB URL (required)
  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);

  // Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  // Assign the maximum retry of token generation
  config.max_token_generation_retry = 5;

  // Initialize the library with the Firebase authen and config
  Firebase.begin(&config, &auth);

  // Getting the user UID might take a few seconds
  Serial.println("Getting User UID");
  while ((auth.token.uid) == "") {
    Serial.print('.');
    delay(1000);
  }
  // Print user UID
  uid = auth.token.uid.c_str();
  Serial.print("User UID: ");
  Serial.println(uid);

  // Update database path
  databasePath = "/UsersData/";

  // Update database path for sensor readings
  distPath = databasePath + "/distance"; // --> UsersData/<user_uid>/temperature

}

void loop(){
  // Send new readings to database
  if (Firebase.ready() && (millis() - sendDataPrevMillis > timerDelay || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();

    float distance = getDistance();

    Serial.println(distance);
    // Send readings to database:
    sendFloat(distPath, distance);
  }

  if(digitalRead(D3)==0){
    createAP();
  }

}

void blinkLedOnce(){
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  return;
}