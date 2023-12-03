#ifndef ARDUINOLIBREDESV2_MQTTCLIENT_H
#define ARDUINOLIBREDESV2_MQTTCLIENT_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <functional>

#if defined(ESP8266) || defined(ESP32)
#include <functional>
#define MQTT_CALLBACK_SIGNATURE std::function<void(char*, uint8_t*, unsigned int)> callback
#else
#define MQTT_CALLBACK_SIGNATURE void (*callback)(char*, uint8_t*, unsigned int)
#endif

class MQTTClient {
public:
    MQTTClient(const char* ssid, const char* password, const char* mqttServerUrl);
    void connect();
    void loop();
    void addListener(const char* topic, MQTT_CALLBACK_SIGNATURE);
    void publish(const char* topic, const char* message);

private:
    WiFiClient _wifiClient;
    PubSubClient _mqttClient;

    const char* _ssid;
    const char* _password;
    const char* _mqttServer;

    struct Listener {
        const char* topic;
        MQTT_CALLBACK_SIGNATURE;
    };

    std::vector<Listener> _listeners;
};


#endif //ARDUINOLIBREDESV2_MQTTCLIENT_H
