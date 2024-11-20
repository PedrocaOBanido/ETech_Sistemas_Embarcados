#include <Arduino.h>

const int LED_BUILTIN = 2;
bool led_state = true;


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  for (auto i = 0; i < 5; i++)
  {
    digitalWrite(LED_BUILTIN, !led_state);
    led_state = !led_state;
    delay(1000);
    Serial.println(i);
  }
  
  esp_deep_sleep(10^6);

}

void loop() {
  digitalWrite(LED_BUILTIN, !led_state);
  led_state = !led_state;
  delay(1000);
}
