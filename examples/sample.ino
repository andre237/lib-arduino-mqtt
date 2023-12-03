#include <DigitalGPIO.h>
#include <SensorDeLuz.h>
#include <SensorDeTemperatura.h>
#include <DisplayLCD16X2.h>
#include <PubSubClient.h>

SensorDeLuz luzSensor(0);
SensorDeTemperatura tempSensor(5);

DigitalGPIO releLampada(7);
DigitalGPIO releVentilador(8);

DisplayLCD16X2 display(0x27);

#include <MQTTClient.h>

// Replace these with your WiFi and MQTT details
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* mqtt_server = "mqtt_server_ip";

MQTTClient mqttClient(ssid, password, mqtt_server);

void setup() {
  Serial.begin(9600);
  display.escreverLinha1("Testando");
  mqttClient.connect();
  mqttClient.addListener("gpios/lampada", callbackLampadas);
}

void loop() {
  delay(100);
  mqttClient.loop();

  if (luzSensor.getValorAtual() > 100) {
    releLampada.liga();
  } else {
    releLampada.desliga();
  }
}

void callbackLampadas(char* topic, byte* payload, unsigned int length) {
  // lógica para alterar o estado da lampada
}

