#include <Arduino.h>

#include "config/config.h"
#include "devices/RelayMqtt.h"
#include "devices/Switch.h"
#include "utils/MqttClient.h"

RelayMqtt relay1 = RelayMqtt(RELAY1_PIN, false, RELAY1_TOPIC);
RelayMqtt relay2 = RelayMqtt(RELAY2_PIN, false, RELAY2_TOPIC);
RelayMqtt relay3 = RelayMqtt(RELAY3_PIN, false, RELAY3_TOPIC);

Switch switchRelay1 = Switch(SWITCH_RELAY1_PIN, LOW);
Switch switchRelay2 = Switch(SWITCH_RELAY2_PIN, LOW);
Switch switchRelay3 = Switch(SWITCH_RELAY3_PIN, LOW);

WiFiClient wifiClient;
MqttClient mqttClient = MqttClient(wifiClient, mqtt_server, 1883);

void mqttMessageCallback(char *topic, byte *payload, unsigned int length) {
  relay1.onMessageReceived(topic, payload, length);
  relay2.onMessageReceived(topic, payload, length);
  relay3.onMessageReceived(topic, payload, length);
}

void mqttConnectedCallback(PubSubClient &client) {
  relay1.onConnected(client);
  relay2.onConnected(client);
  relay3.onConnected(client);
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
}