#include <Arduino.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin("FPF-5Ghz", "10203040");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(" ☆*: .｡. o(≧▽≦)o .｡.:*☆ ");
  }
  Serial.println();
  Serial.println("Conectado!");
  Serial.println(WiFi.localIP());
}

void loop() {
  //
}
