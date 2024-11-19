#include <Arduino.h>
#include <vector>
#include <iostream>

std::vector<int> vector;

void setup() {
  //
  Serial.begin(9600);
}

void loop() {
  //
  if(Serial.available() > 0){
    String inStream = Serial.readStringUntil('\n');
    inStream.trim();
    int number = inStream.toInt();
    if (number == -1)
    {
      for (auto i = 0; i < vector.size(); i++)
      {
        int soma;
        soma += vector.at(i);

        int media = soma / vector.size();
        Serial.println(media);
        vector.clear();
      }
      
    }
    else
    {
      vector.push_back(number);
      Serial.println("**");
    }
    
    
    

  }
}