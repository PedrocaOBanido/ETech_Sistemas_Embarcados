#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o LCD I2C (endereço 0x27, 16 colunas, 2 linhas)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Interativo LCD");
  Serial.begin(9600);
  Serial.println("Bem-vindo ao menu interativo do LCD!");
  Serial.println("Comandos disponíveis:");
  Serial.println("1 - Mensagem personalizada");
  Serial.println("2 - Limpar tela");
  Serial.println("3 - Apagar backlight");
  Serial.println("4 - Ligar backlight");
}

void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "1") {
      Serial.println("Digite sua mensagem (máx 32 caracteres):");
      while (Serial.available() == 0) {
        // Aguarda entrada do usuário
      }
      String mensagem = Serial.readStringUntil('\n');
      mensagem.trim();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(mensagem.substring(0, 16));
      if (mensagem.length() > 16) {
        lcd.setCursor(0, 1);
        lcd.print(mensagem.substring(16, 32));
      }
      Serial.println("Mensagem exibida no LCD!");
    } 
    else if (comando == "2") {
      lcd.clear();
      Serial.println("Tela do LCD limpa.");
    } 
    else if (comando == "3") {
      lcd.noBacklight();
      Serial.println("Backlight do LCD apagado.");
    } 
    else if (comando == "4") {
      lcd.backlight();
      Serial.println("Backlight do LCD ligado.");
    } 
    else {
      Serial.println("Comando inválido. Tente novamente.");
    }
  }
}