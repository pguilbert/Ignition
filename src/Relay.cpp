#include "Relay.h"

Relay::Relay(int relayPin, bool isOnByDefault)
    : relayPin(relayPin), isCurrentlyOn(isOnByDefault) {}

void Relay::update() { digitalWrite(this->relayPin, this->isCurrentlyOn); }

void Relay::ensureOn() { this->isCurrentlyOn = true; }

void Relay::ensureOff() { this->isCurrentlyOn = false; }

bool Relay::toggle() {
  this->isCurrentlyOn = !this->isCurrentlyOn;

  return this->isCurrentlyOn;
}

bool Relay::isOn() { return this->isCurrentlyOn; }