#include <Arduino.h>
#include "config.h"
 
const relay1 = Relay(RELAY1_PIN, false);
const relay2 = Relay(RELAY2_PIN, false);
const relay3 = Relay(RELAY3_PIN, false);

const switchRelay1 = Switch(SWITCH_RELAY1_PIN, LOW);
const switchRelay2 = Switch(SWITCH_RELAY2_PIN, LOW);
const switchRelay3 = Switch(SWITCH_RELAY3_PIN, LOW);

void setup() {
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);

  pinMode(SWITCH_RELAY1_PIN, INPUT_PULLUP);
  pinMode(SWITCH_RELAY2_PIN, INPUT_PULLUP);
  pinMode(SWITCH_RELAY3_PIN, INPUT_PULLUP);
}

void loop() {

}