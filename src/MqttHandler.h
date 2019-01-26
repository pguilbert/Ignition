#ifndef MqttHandler_h
#define MqttHandler_h

class MqttHandler {
 public:
  virtual void onConnected(PubSubClient& client){};
  virtual void onMessageReceived(char* topic, byte* payload,
                                 unsigned int length){};

 protected:
  PubSubClient mqttClient;
};

#endif