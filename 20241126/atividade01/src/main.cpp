#include <Arduino.h>
#include <Pinout.h>
#include "DriverWiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Dispostivo iniciado! Ψ(￣∀￣)Ψ");
  pinMode(led_pin, OUTPUT);
}

void loop() {
  //
  while (Serial.available() == 0)
  {
    Serial.println("Digite o SSID: (づ￣ 3￣)づ ...");
    while(Serial.available() == 0);
    String ssid = Serial.readStringUntil('\n');
    Serial.println("Digite a senha: (ˉ▽￣～) ...");
    while(Serial.available() == 0);
    String password = Serial.readStringUntil('\n');
    Serial.print("O SSID digitado foi: ");
    Serial.print(ssid);
    Serial.println();
    ssid.trim();
    password.trim();
    Serial.print("A senha digitada foi: ");
    Serial.print(password);
    Serial.println();
    Serial.print("tudo certo? o(*￣▽￣*)o  (y/n)");
    while(Serial.available() == 0);
    char c = Serial.read();
    if(c == 'y'){
      connectWiFi(ssid, password);
      Serial.println("Conectado! (～￣▽￣)～");
      // while(Serial.available() == 0);
      // char c = Serial.read();
      // if (c == 'r')
      // {
      //   loop();
      // }
      
    }
  }
}
