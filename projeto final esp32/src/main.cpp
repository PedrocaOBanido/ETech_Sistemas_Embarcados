#include <WiFi.h>
#include <PubSubClient.h>

const char* WIFI_SSID = "Etech";
const char* WIFI_PASSWORD = "al40030f";

const char* MQTT_BROKER = "10.31.3.108"; 
const int MQTT_PORT = 1883;
const char* CLIENT_ID = "ESP32_Device_pedro";

// Publish topics
const char* TEMPERATURE_TOPIC = "/pedro/temperatura";
const char* HUMIDITY_TOPIC = "/pedro/umidade";
const char* LDR_TOPIC = "/pedro/ldr";

/// Subscribe topics
const char* RELAY_TOPIC = "/pedro/rele";
const char* MOTOR_TOPIC = "pedroraphael/motor";
const char* VELOCITY_TOPIC = "/pedro/velocidade";

const int LED_PIN = 2;

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void connectToWiFi() {
    Serial.println("Connecting to WiFi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    bool led_state = true;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        digitalWrite(LED_PIN, led_state);
        led_state = !led_state;
    }
    digitalWrite(LED_PIN, HIGH);

    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void checkWiFiConnection() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi disconnected, attempting to reconnect...");
        connectToWiFi();
    }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    
    String message = "";
    for (unsigned int i = 0; i < length; i++) {
        message += (char)payload[i];
    }

    if (String(topic) == MOTOR_TOPIC) {
        Serial2.println("MOTOR:" + message);
    } else if (String(topic) == VELOCITY_TOPIC) {
        Serial2.println("VELOCITY:" + message);
    } else if (String(topic) == RELAY_TOPIC) {
        Serial2.println("RELAY:" + message);
    }
}

void reconnectMQTT() {
    while (!mqttClient.connected()) {
        Serial.println("Attempting MQTT Connection...");
        
        if (mqttClient.connect(CLIENT_ID)) {
            Serial.println("MQTT Connected!");
            mqttClient.subscribe(RELAY_TOPIC);
            mqttClient.subscribe(MOTOR_TOPIC);
            mqttClient.subscribe(VELOCITY_TOPIC);
        } else {
            Serial.print("Failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println(" Retrying in 5 seconds");
            delay(5000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    Serial2.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    connectToWiFi();
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
    mqttClient.setCallback(mqttCallback);
}

void loop() {

  checkWiFiConnection();

  if (!mqttClient.connected()) {
      reconnectMQTT();
  }
  mqttClient.loop();
  if (Serial2.available() > 0) {
    String message = Serial2.readStringUntil('\n');
    int index_1 = message.indexOf('-');
    if (index_1 > 0) {
        uint16_t ldr_value = message.substring(0, index_1).toInt();
        int index_2 = message.indexOf('-', index_1 + 1);
        if (index_2 > 0) {
            float temperature = message.substring(index_1 + 1, index_2).toFloat();
            float humidity = message.substring(index_2 + 1).toFloat();
            Serial.print("LDR: ");
            Serial.println(ldr_value);
            Serial.print("Temperature: ");
            Serial.println(temperature);
            Serial.print("Humidity: ");
            Serial.println(humidity);

            mqttClient.publish(LDR_TOPIC, String(ldr_value).c_str());
            mqttClient.publish(TEMPERATURE_TOPIC, String(temperature, 2).c_str());
            mqttClient.publish(HUMIDITY_TOPIC, String(humidity, 2).c_str());
        } else {
            Serial.println("Error: invalid message format");
        }
    } else {
        Serial.println("Error: invalid message format available");
    }
  }  
  delay(10);
}

// lib_deps = knolleary/PubSubClient@^2.8