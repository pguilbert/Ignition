#include <Arduino.h>
#include "config.h"

#include "Relay.h"
#include "Switch.h"
 
Relay relay1 = Relay(RELAY1_PIN, false);
Relay relay2 = Relay(RELAY2_PIN, false);
Relay relay3 = Relay(RELAY3_PIN, false);

Switch switchRelay1 = Switch(SWITCH_RELAY1_PIN, LOW);
Switch switchRelay2 = Switch(SWITCH_RELAY2_PIN, LOW);
Switch switchRelay3 = Switch(SWITCH_RELAY3_PIN, LOW);

void setup() {
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);

  pinMode(SWITCH_RELAY1_PIN, INPUT_PULLUP);
  pinMode(SWITCH_RELAY2_PIN, INPUT_PULLUP);
  pinMode(SWITCH_RELAY3_PIN, INPUT_PULLUP);
}

void linkSwitchWithRelay(Switch &swtch, Relay &relay) {
  if(swtch.justPressed()) {
    relay.toggle();    
  }

  relay.update();
  swtch.update();
}

void loop() {
  linkSwitchWithRelay(switchRelay1, relay1);
  linkSwitchWithRelay(switchRelay2, relay2);
  linkSwitchWithRelay(switchRelay3, relay3);
}