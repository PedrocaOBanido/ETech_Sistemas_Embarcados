#include "DriverWiFi.h"
#include "Pinout.h"
#include "GeneralDefinitions.h"

void connectWiFi(String ssid, String password){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    
    bool state = true;
    while (WiFi.status() != WL_CONNECTED)
    {
        #ifdef SERAIL_DEBUG
            Serail.println(" (づ￣ 3￣)づ ");
        #endif
        Serial.print(" (┬┬﹏┬┬) ");
        digitalWrite(led_pin, state);
        delay(500);
        state = !state;
    }
    Serial.println();
    digitalWrite(led_pin, false);    
}