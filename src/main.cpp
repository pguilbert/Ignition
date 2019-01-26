#include <Arduino.h>

#include "config.h"

#include "Relay.h"
#include "Switch.h"

#include "MqttClient.h"
#include "RelayMqttWrapper.h"

Relay relay1 = Relay(RELAY1_PIN, false);
Relay relay2 = Relay(RELAY2_PIN, false);
Relay relay3 = Relay(RELAY3_PIN, false);
RelayMqttWrapper relay1MqttWrapper = RelayMqttWrapper(relay1, RELAY1_TOPIC);
RelayMqttWrapper relay2MqttWrapper = RelayMqttWrapper(relay2, RELAY2_TOPIC);
RelayMqttWrapper relay3MqttWrapper = RelayMqttWrapper(relay3, RELAY3_TOPIC);

Switch switchRelay1 = Switch(SWITCH_RELAY1_PIN, LOW);
Switch switchRelay2 = Switch(SWITCH_RELAY2_PIN, LOW);
Switch switchRelay3 = Switch(SWITCH_RELAY3_PIN, LOW);

WiFiClient wifiClient;
MqttClient mqttClient = MqttClient(wifiClient, mqtt_server, 1883);

void mqttMessageCallback(char *topic, byte *payload, unsigned int length) {
  relay1MqttWrapper.onMessageReceived(topic, payload, length);
  relay2MqttWrapper.onMessageReceived(topic, payload, length);
  relay3MqttWrapper.onMessageReceived(topic, payload, length);
}

void mqttConnectedCallback(PubSubClient &client) {
  relay1MqttWrapper.onConnected(client);
  relay2MqttWrapper.onConnected(client);
  relay3MqttWrapper.onConnected(client);
}

void setup() {
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);

  pinMode(SWITCH_RELAY1_PIN, INPUT_PULLUP);
  pinMode(SWITCH_RELAY2_PIN, INPUT_PULLUP);
  pinMode(SWITCH_RELAY3_PIN, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  mqttClient.setup();

  mqttClient.setMqttMessageCallback(mqttMessageCallback);
  mqttClient.setMqttConnectedCallback(mqttConnectedCallback);
}

void linkSwitchWithRelay(Switch &swtch, Relay &relay) {
  if (swtch.justPressed()) {
    relay.toggle();
  }

  relay.update();
  swtch.update();
}

void loop() {
  linkSwitchWithRelay(switchRelay1, relay1);
  linkSwitchWithRelay(switchRelay2, relay2);
  linkSwitchWithRelay(switchRelay3, relay3);

  mqttClient.update();
  relay1MqttWrapper.update();
  relay2MqttWrapper.update();
  relay3MqttWrapper.update();
}