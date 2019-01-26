#include "Relay.h"

Relay::Relay(int relayPin, bool isOnByDefault)
    : relayPin(relayPin), isCurrentlyOn(isOnByDefault) {}

void Relay::update() { digitalWrite(this->relayPin, this->isCurrentlyOn); }

void Relay::ensureOn() {
  bool stateChanged = !this->isCurrentlyOn;
  this->isCurrentlyOn = true;

  if (stateChanged) {
    this->onStateChanged();
  }
}

void Relay::ensureOff() {
  bool stateChanged = this->isCurrentlyOn;
  this->isCurrentlyOn = false;

  if (stateChanged) {
    this->onStateChanged();
  }
}

bool Relay::toggle() {
  this->isCurrentlyOn = !this->isCurrentlyOn;
  this->onStateChanged();
  return this->isCurrentlyOn;
}

bool Relay::isOn() { return this->isCurrentlyOn; }