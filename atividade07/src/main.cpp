#include <Arduino.h>

const int PIN_LED = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    Serial.println("insira o comando");
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "on")
    {
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LIGADO!");
    }
    else if (command = "off")
    {
      digitalWrite(PIN_LED, LOW);
      Serial.println("DESLIGADO!");
    }
  
  }  
  
}
