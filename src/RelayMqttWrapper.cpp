#include "RelayMqttWrapper.h"

RelayMqttWrapper::RelayMqttWrapper(Relay& relay, const char* relayId) : relay(relay), relayId(relayId) {
    this->previousRelayState = relay.isOn();
}

void RelayMqttWrapper::update() {
    if(this->previousRelayState != this->relay.isOn()) {
        this->previousRelayState = this->relay.isOn();
        this->onRelayStateChanged();
    }
}

void RelayMqttWrapper::onConnected(PubSubClient& client) {
    this->mqttClient = client;
}

void RelayMqttWrapper::onMessageReceived(char* topic, byte* payload, unsigned int length) {
    
}

void RelayMqttWrapper::onRelayStateChanged() {
    const char* state = "{\"state\": \"ON\"}";
    this->mqttClient.publish(this->relayId, state);
}