#include <Arduino.h>

bool ledState = false;


void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  Serial2.println(random(1, 10));
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(1000);
}
