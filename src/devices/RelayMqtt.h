#ifndef RelayMqtt_h
#define RelayMqtt_h

#include <PubSubClient.h>
#include "Relay.h"

class RelayMqtt : public Relay {
 private:
  String relayTopicBase;
  PubSubClient mqttClient;

 protected:
  virtual void onStateChanged();

 public:
  RelayMqtt(int relayPin, bool isOnByDefault, String relayTopicBase);
  void onConnected(PubSubClient& client);
  void onMessageReceived(char* topic, byte* payload, unsigned int length);
};

#endif
