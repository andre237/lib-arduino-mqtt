//
// Created by André Spironello Tibola on 03/12/23.
//

#include "MQTTClient.h"

#include <utility>
#include <string>
#include "Arduino.h"

MQTTClient::MQTTClient(const char *ssid, const char *password, const char *mqttServerUrl) :
    _ssid(ssid), _password(password), _mqttServer(mqttServerUrl), _mqttClient(_wifiClient) {}

void MQTTClient::connect() {
    WiFi.begin(_ssid, _password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    _mqttClient.setServer(_mqttServer, 1883); // Replace 1883 with the port your MQTT broker is using
    _mqttClient.setCallback([this](char* topic, byte* payload, unsigned int length) {
        Serial.print("Message received on topic: ");
        Serial.println(topic);

        for (const auto& listener : _listeners) {
            if (strcmp(topic, listener.topic) == 0) {
                listener.callback(topic, payload, length);
            }
        }
    });

    _reconnect();
}

void MQTTClient::_reconnect() {
    std::string clientId = "esp8266-client-";
    clientId.append(WiFi.macAddress().c_str());

    while (!_mqttClient.connected()) {
        if (_mqttClient.connect(clientId.c_str())) {
            for (const auto& listener : _listeners) {
                _mqttClient.subscribe(listener.topic);
            }
        } else {
            delay(1000);
        }
    }
}

void MQTTClient::loop() {
    _reconnect();
    _mqttClient.loop();
}

void MQTTClient::publish(const char *topic, const char *message) {
    _mqttClient.publish(topic, message);
}

void MQTTClient::addListener(const char *topic, MQTT_CALLBACK_SIGNATURE) {
    _listeners.push_back({topic, callback});
    _mqttClient.subscribe(topic);
}
