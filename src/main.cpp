#include <Arduino.h>

#include "config.h"

#include "MqttClient.h"

#include "Relay.h"
#include "RelayMqttWrapper.h"
#include "Switch.h"

Relay relay1 = Relay(RELAY1_PIN, false);
Relay relay2 = Relay(RELAY2_PIN, false);
Relay relay3 = Relay(RELAY3_PIN, false);

Switch switchRelay1 = Switch(SWITCH_RELAY1_PIN, LOW);
Switch switchRelay2 = Switch(SWITCH_RELAY2_PIN, LOW);
Switch switchRelay3 = Switch(SWITCH_RELAY3_PIN, LOW);

WiFiClient wifiClient;
MqttClient mqttClient = MqttClient(wifiClient, mqtt_server, 1883);

void setup() {
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  
  pinMode(SWITCH_RELAY1_PIN, INPUT_PULLUP);
  pinMode(SWITCH_RELAY2_PIN, INPUT_PULLUP);
  pinMode(SWITCH_RELAY3_PIN, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  mqttClient.setup();
}

void linkSwitchWithRelay(Switch &swtch, Relay &relay) {
  if(swtch.justPressed()) {
    relay.toggle();    
  }

  relay.update();
  swtch.update();
}

void loop() {
  mqttClient.update();
  
  linkSwitchWithRelay(switchRelay1, relay1);
  linkSwitchWithRelay(switchRelay2, relay2);
  linkSwitchWithRelay(switchRelay3, relay3);
}