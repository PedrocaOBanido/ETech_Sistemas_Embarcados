#include <Arduino.h>
#include <ArduinoJson.h>

JsonDocument doc;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //
  if (Serial.available() > 0)
  {
    String msg = Serial.readStringUntil('\n');
    //
    DeserializationError error = deserializeJson(doc, msg);
    if (!error)
    {
      bool led_state = doc["LED_RETURN"];
      digitalWrite(LED_BUILTIN, led_state);
      doc.clear();

      doc["LED_RETURN"] = "OK";

      String saida;
      serializeJson(doc, saida);
      Serial.println(saida);
    }
  }
  
}
