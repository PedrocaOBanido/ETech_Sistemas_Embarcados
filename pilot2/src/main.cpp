#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  analogWrite(11, 127);
  analogWrite(10, 200);
  analogWrite(9, 80);

}

void loop() {

  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  Serial.println("A");
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(9, LOW);
  Serial.println("B");
  delay(1000);
}