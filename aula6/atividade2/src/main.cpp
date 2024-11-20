#include <Arduino.h>
const int LED_BUILTIN = 2; 
const int WAKEUP_PIN = GPIO_NUM_33;
void handleWakeUpReason() {
  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();

  if (wakeup_reason == ESP_SLEEP_WAKEUP_TIMER) {
    Serial.println("Despertado pelo temporizador. Executando tarefa...");
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_BUILTIN, HIGH); 
      delay(500); 
      digitalWrite(LED_BUILTIN, LOW); 
      delay(500);
    }
  } else if (wakeup_reason == ESP_SLEEP_WAKEUP_EXT0) {
    Serial.println("Despertado pelo pino externo. Nenhuma tarefa a ser executada.");
  } else {
    Serial.println("Primeira inicialização ou motivo desconhecido.");
  }
}
void setup() {

  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  handleWakeUpReason();

  esp_sleep_enable_timer_wakeup(10 * 1000000); // (em microssegundos)

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 0);

  Serial.println("Entrando em modo de sono profundo por 10 segundos...");
  esp_deep_sleep_start();
}

void loop() {
}
