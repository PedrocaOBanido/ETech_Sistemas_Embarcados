#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

HTTPClient http;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("FPF-5Ghz", "10203040");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(" (┬┬﹏┬┬) ");
  }
  Serial.println("Conectado! (ˉ▽￣～)(～￣▽￣)～ ");
  
}

void loop() {
 
    http.begin("https://api.adviceslip.com/advice");

    int status_code = http.GET();

    Serial.println(status_code);

    if (status_code == 200){
       Serial.println(http.getString());
    }    
    delay(5000);  

}
