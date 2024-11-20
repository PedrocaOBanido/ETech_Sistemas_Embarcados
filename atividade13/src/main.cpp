#include <Arduino.h>

int valMin = 0;
int valMinOut = 0;
int valMax = 1023;
int valMaxOut = 5;

int x = 115;

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    // fazer um vetor "valores" ao invés de utilizar substrings
    String valores = Serial.readStringUntil('\n');
    Serial.println("<<<<");
    Serial.println(valores);
    int index_1 = valores.indexOf(',');
    String x1 = valores.substring(0, index_1);
    
  }
  
}
