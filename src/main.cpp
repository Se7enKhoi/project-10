#include <Arduino.h>

#define PIR_PIN 2       // Digital input pin connected to PIR Sensor OUT
#define LED_PIN 13      // Digital output pin for LED (or Buzzer)

int lastPirState = -1;  

void setup() {
    Serial.begin(9600);
    
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    
    digitalWrite(LED_PIN, LOW);
    
    Serial.println("=== ATmega328 PIR Motion Detector Ready ===");
}

void loop() {
    int currentPirState = digitalRead(PIR_PIN);

  
    if (currentPirState != lastPirState) {
        if (currentPirState == HIGH) {
            digitalWrite(LED_PIN, HIGH);
            Serial.println("[STATUS] Motion Detected!");
        } else {
            digitalWrite(LED_PIN, LOW);
            Serial.println("[STATUS] No Motion Detected.");
        }
        
       
        lastPirState = currentPirState;
    }
    delay(50); 
}
