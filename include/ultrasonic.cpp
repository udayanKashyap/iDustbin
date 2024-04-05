#include <Arduino.h>

const int trigPin = D6;
const int echoPin = D5;

float getDistance(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(echoPin, HIGH);
    
    // Calculate the distance
    float distance = duration * 0.034/2;
    return distance;
}
