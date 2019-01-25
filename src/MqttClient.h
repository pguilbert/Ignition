#ifndef MqttClient_h
#define MqttClient_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "MqttHandler.h"

#define MQTT_CONNECTED_CALLBACK_SIGNATURE std::function<void(PubSubClient&)> connectedCallback

class MqttClient {
    public:

    MqttClient(WiFiClient wifiClient, const char* server, const int port);

    void setup();
    void update();

    void setMqttMessageCallback(MQTT_CALLBACK_SIGNATURE);
    void setMqttConnectedCallback(MQTT_CONNECTED_CALLBACK_SIGNATURE);

    private:
    bool reconnect();
    void mqttCallback(char* topic, byte* payload, unsigned int length);

    PubSubClient client;
    const char* server;
    const int port;
    MQTT_CONNECTED_CALLBACK_SIGNATURE;
    long lastReconnectAttempt = 0;
};

#endif