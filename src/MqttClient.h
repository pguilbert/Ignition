#ifndef MqttClient_h
#define MqttClient_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "MqttHandler.h"

class MqttClient {
    public:

    MqttClient(WiFiClient wifiClient, const char* server, const int port);

    void setup();
    void update();
    void onConnected(PubSubClient client);

    private:
    bool reconnect();
    void mqttCallback(char* topic, byte* payload, unsigned int length);

    PubSubClient client;
    const char* server;
    const int port;
    long lastReconnectAttempt = 0;
};

#endif