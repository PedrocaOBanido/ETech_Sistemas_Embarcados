#include <Arduino.h>

void setup() {
  //
  Serial.begin(4800);
}

void loop() {
  // if (Serial.available())
  // {
  // String msg = Serial.readStringUntil('\n');
  // Serial.println(msg);
  
  // }  
  // delay(1000);
  if (Serial.available())
  {
  uint8_t msg = Serial.read();
  Serial.println(msg);
  
  }  
  delay(1000);
}
