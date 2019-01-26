#ifndef RelayMqttWrapper_h
#define RelayMqttWrapper_h

#include <PubSubClient.h>

#include "MqttHandler.h"
#include "Relay.h"

class RelayMqttWrapper : public MqttHandler {
 public:
  RelayMqttWrapper(Relay& relay, const char* relayTopicBase);

  void update();
  void onConnected(PubSubClient& client);
  void onMessageReceived(char* topic, byte* payload, unsigned int length);

 private:
  void onRelayStateChanged();
  Relay& relay;
  const char* relayTopicBase;
  bool previousRelayState;
};

#endif