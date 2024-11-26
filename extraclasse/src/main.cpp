#include <Arduino.h>

#define KEY_1 19
#define KEY_2 18
#define KEY_3 4
#define KEY_4 5
#define KEY_5 6
#define KEY_6 7
#define KEY_7 8
#define KEY_8 9
#define LED_RED 1
#define LED_BLUE 2
#define LED_GREEN 3

void setup() {
  Serial.begin(115200);
  Serial.println("Hardware iniciado...");
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(KEY_1, INPUT_PULLUP);
  pinMode(KEY_2, INPUT_PULLUP);
  pinMode(KEY_3, INPUT_PULLUP);
  pinMode(KEY_4, INPUT_PULLUP);
  pinMode(KEY_5, INPUT_PULLUP);
  pinMode(KEY_6, INPUT_PULLUP);
  pinMode(KEY_7, INPUT_PULLUP);
  pinMode(KEY_8, INPUT_PULLUP);
}

void loop() {
  bool key1 = !digitalRead(KEY_1);
  bool key2 = !digitalRead(KEY_2);
  bool key3 = !digitalRead(KEY_3);
  bool key4 = !digitalRead(KEY_4);
  bool key5 = !digitalRead(KEY_5);
  bool key6 = !digitalRead(KEY_6);
  bool key7 = !digitalRead(KEY_7);
  bool key8 = !digitalRead(KEY_8);

  if (key8) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, LOW);
  } else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, LOW);

    if (key1) digitalWrite(LED_RED, HIGH);
    if (key2) digitalWrite(LED_BLUE, HIGH);
    if (key3) digitalWrite(LED_GREEN, HIGH);
    if (key4) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_BLUE, HIGH);
    }
    if (key5) {
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_GREEN, HIGH);
    }
    if (key6) {
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, HIGH);
    }
    if (key7) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_GREEN, HIGH);
    }
  }
}
