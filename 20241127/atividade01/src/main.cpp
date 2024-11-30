#include <Arduino.h>
#include <WiFi.h>
#include <WiFi.h>
#include <WebServer.h>

#define LED_PIN 2  

WebServer sv(80);

const char* ssid = "Etech"; 
const char* senha = "al40030f";


void turnONLed() {
  digitalWrite(LED_PIN, HIGH);  
  sv.send(200, "text/html", "<h1>LED Ligado</h1><a href=\"/off\">Desligar</a>");
}

// Função para desligar o LED
void turnOFFLed() {
  digitalWrite(LED_PIN, LOW);  // Desliga o LED
  sv.send(200, "text/html", "<h1>LED Desligado</h1><a href=\"/on\">Ligar</a>");
}

void paginaInicial() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html lang="pt-br">
    <head>
      <meta charset="UTF-8">
      <title>Controle do LED</title>
    </head>
    <body>
      <h1>Controle do LED</h1>
      <a href="/on">Ligar LED</a><br>
      <a href="/off">Desligar LED</a>
    </body>
    </html>
    )rawliteral";

  sv.send(200, "text/html", html);
}

void nao_encontrado() {
  sv.send(404, "text/plain", "Rota não encontrada");
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  delay(100);

  Serial.print("Conectando-se a: ");
  Serial.println(ssid);

  WiFi.begin(ssid, senha);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  sv.on("/", paginaInicial);        
  sv.on("/on", turnONLed);       
  sv.on("/off", turnOFFLed);  
  sv.onNotFound(nao_encontrado);  

  sv.begin();
  Serial.println("Servidor Online");
}

void loop() {
  sv.handleClient();
}
