#include <Arduino.h>
#include <SoftwareSerial.h>

const int rx_pin = 8;
const int tx_pin = 9;

SoftwareSerial serial_esp (rx_pin, tx_pin);

void setup() {
  Serial.begin(9600);
  serial_esp.begin(9600);
}

void loop() {
  if(serial_esp.available() > 0){
    String message = serial_esp.readStringUntil('\n');
    Serial.println(message);
  }
  delay(10);
}