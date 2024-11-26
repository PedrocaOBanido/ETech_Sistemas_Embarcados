#include <Arduino.h>

int valor;

void setup(){
  Serial.begin(9600);
  pinMode(A1, INPUT);
}

void loop(){
  valor = analogRead(A1);
  Serial.println(valor);
  delay(100);
}
