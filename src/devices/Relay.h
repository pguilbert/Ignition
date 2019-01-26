#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay {
 public:
  Relay(int relayPin, bool isOnByDefault);

  void update();

  void ensureOn();
  void ensureOff();
  bool toggle();
  bool isOn();

 protected:
  virtual void onStateChanged() {}

 private:
  int relayPin;
  bool isCurrentlyOn;
};

#endif