#include "MqttClient.h"

MqttClient::MqttClient(WiFiClient wifiClient, const char* server, int port) : 
    client(wifiClient), 
    server(server), 
    port(port) {
}

void MqttClient::setMqttMessageCallback(MQTT_CALLBACK_SIGNATURE) {
    client.setCallback(callback);
}

void MqttClient::setMqttConnectedCallback(MQTT_CONNECTED_CALLBACK_SIGNATURE) {
    this->connectedCallback = connectedCallback;
}

void MqttClient::setup() {
    client.setServer(this->server, this->port);
}

void MqttClient::update() {
    if(!this->client.connected()) {
        long now = millis();
        if (now - this->lastReconnectAttempt > 5000) {
            lastReconnectAttempt = now;
            if (this->reconnect()) {
                lastReconnectAttempt = 0;
            }
        }
    }
    else {
        client.loop();
    }
}

bool MqttClient::reconnect() {
    if (client.connect("esp8266Client")) {
        this->connectedCallback(client);
    }
    return client.connected();
}