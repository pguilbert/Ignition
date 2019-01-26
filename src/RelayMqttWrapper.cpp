#include "RelayMqttWrapper.h"

RelayMqttWrapper::RelayMqttWrapper(Relay& relay, const char* relayTopicBase)
    : relay(relay), relayTopicBase(relayTopicBase) {
  this->previousRelayState = relay.isOn();
}

void RelayMqttWrapper::update() {
  if (this->previousRelayState != this->relay.isOn()) {
    this->previousRelayState = this->relay.isOn();
    this->onRelayStateChanged();
  }
}

void RelayMqttWrapper::onConnected(PubSubClient& client) {
  this->mqttClient = client;
  client.subscribe((String(this->relayTopicBase) + String("/set")).c_str());
}

void RelayMqttWrapper::onMessageReceived(char* topic, byte* payload,
                                         unsigned int length) {
  if (String(topic) == (String(this->relayTopicBase) + String("/set"))) {
    if (length == 3) {
      relay.ensureOff();
    } else {
      relay.ensureOn();
    }

    this->onRelayStateChanged();
  }
}

void RelayMqttWrapper::onRelayStateChanged() {
  this->mqttClient.publish(this->relayTopicBase,
                           this->relay.isOn() ? "ON" : "OFF");
}