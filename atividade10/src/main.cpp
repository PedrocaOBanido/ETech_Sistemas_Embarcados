#include <Arduino.h>

const int LED_PIN = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  String command = Serial.readStringUntil('\n');
  int number = command.toInt();
  switch ()
  {
  case 1:
    digitalWrite(LED_PIN, HIGH);
    break;
  
  default:
    break;
  }
}
