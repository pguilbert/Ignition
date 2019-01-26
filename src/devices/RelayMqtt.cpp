#include "RelayMqtt.h"

RelayMqtt::RelayMqtt(int relayPin, bool isOnByDefault, String relayTopicBase)
    : Relay(relayPin, isOnByDefault), relayTopicBase(relayTopicBase) {}

void RelayMqtt::onConnected(PubSubClient& client) {
  this->mqttClient = client;
  client.subscribe((this->relayTopicBase + String("/set")).c_str());
}

void RelayMqtt::onMessageReceived(char* topic, byte* payload,
                                  unsigned int length) {
  if (String(topic) == (String(this->relayTopicBase) + String("/set"))) {
    if (length == 3) {
      this->ensureOff();
    } else {
      this->ensureOn();
    }

    this->onStateChanged();
  }
}

void RelayMqtt::onStateChanged() {
  this->mqttClient.publish(this->relayTopicBase.c_str(),
                           this->isOn() ? "ON" : "OFF");
}