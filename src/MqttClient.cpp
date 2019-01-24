#include "MqttClient.h"


//   client.setServer(mqtt_server, 1883);
//   client.setCallback(mqttCallback);
MqttClient::MqttClient(WiFiClient wifiClient, const char* server, int port) : 
    client(wifiClient), 
    server(server), 
    port(port) {
}

void MqttClient::mqttCallback(char* topic, byte* payload, unsigned int length) {

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
        //exec list of wrapper here...
        client.publish("outTopic","hello world");
        client.subscribe("inTopic");
    }
    return client.connected();
}