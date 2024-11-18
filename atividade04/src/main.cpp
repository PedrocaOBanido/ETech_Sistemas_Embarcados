#include <Arduino.h>

unsigned long time;
bool LED_STATE = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  if (millis() - time >= 2000)
  {
    time = millis();
    LED_STATE = !LED_STATE;
    digitalWrite(LED_BUILTIN, LED_STATE);
  }
  
  
}
