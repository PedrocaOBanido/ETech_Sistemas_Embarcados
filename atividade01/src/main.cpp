#include <Arduino.h>

void setup() {
  pinMode(13, OUTPUT);
  
}

void loop() {
  Serial.println("1");
  digitalWrite(13, HIGH);
  delay(500);
  Serial.println("0");
  digitalWrite(13, LOW);
  delay(500);
}
