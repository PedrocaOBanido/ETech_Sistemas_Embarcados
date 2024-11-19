#include <Arduino.h>

const int LED_PIN = 13;
int count = 0;

void piscaPisca(){
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
 
  for (int i = 0; i < 10; i++)
  {
    // descobrir pq isso não tá parando
    piscaPisca();
  }
  while (true)
  {
    /* code */
  }
  
  
}
