#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <SoftwareSerial.h>

const int RX_PIN = 9;
const int TX_PIN = 8;
const int LDR_PIN = A3;
const int DHT_PIN = 4;
const int RELAY_PIN = 6;
const int MOTOR_PIN = 3;

uint8_t pwm = 0;
bool motor_state = false;

SoftwareSerial new_serial(RX_PIN, TX_PIN);

DHT dht(DHT_PIN, DHT11);

uint16_t readLDR(){
  return analogRead(LDR_PIN);
}

void controlRelay(bool state){
  digitalWrite(RELAY_PIN, state);
}

void controlMotor(){
  if (motor_state){
    analogWrite(MOTOR_PIN, pwm);
  }
  else {
    digitalWrite(MOTOR_PIN, LOW);
  }
}

float readTemp(){
  return dht.readTemperature();
}

float readHum(){
  return dht.readHumidity();
}

void clearSerial(){
  while (new_serial.available()>0){
    new_serial.read();
  }
}

void setup() {
  Serial.begin(9600);
  new_serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  pinMode(DHT_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  dht.begin();
}

void loop()
{
  if (new_serial.available() > 0)
  {
    delay(10);
    String command = new_serial.readStringUntil('\n');
    Serial.println("Command received " + command);
    if (command.startsWith("VELOCITY:"))
    {
      int received_pwd = command.substring(9).toInt();
      if (received_pwd >= 0 && received_pwd <= 255)
      {
        pwm = received_pwd;
        if (motor_state == true)
        {
          controlMotor();
        }
        Serial.println("Motor PWM: " + String(pwm));
      }
      else
      {
        Serial.println("Invalid PWM value");
      }
    }
    else if (command.startsWith("MOTOR:"))
    {
      int received_state = command.substring(6).toInt();
      if (received_state == 0)
      {
        motor_state = false;
        controlMotor();
      }
      else if (received_state == 1)
      {
        motor_state = true;
        controlMotor();
      }
      else
      {
        Serial.println("Invalid motor value");
      }
    }
    else if (command.startsWith("RELAY:"))
    {
      int state = command.substring(6).toInt();
      if (state == 0 || state == 1)
      {
        controlRelay(state);
        Serial.println("Relay state: " + String(state));
      }
      else
      {
        Serial.println("Invalid relay state");
      }
    }
    else
    {
      Serial.println("Invalid command");
    }
    clearSerial();
  }

  uint16_t ldr_value = readLDR();
  float temp = readTemp();
  float hum = readHum();

  if (isnan(temp) || isnan(hum))
  {
    Serial.println("Error to read DHT11");
  }
  else
  {
    new_serial.print(ldr_value);
    new_serial.print("-");
    new_serial.print(temp, 2);
    new_serial.print("-");
    new_serial.println(hum, 2);
    Serial.print("LDR: ");
    Serial.println(ldr_value);
    Serial.print("Temperatura: ");
    Serial.println(temp);
    Serial.print("Umidade: ");
    Serial.println(hum);
  }
  delay(500);
}