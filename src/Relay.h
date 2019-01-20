#ifndef Relay_h
#define Relay_h

class Relay {
    public:

    Relay(int relayPin, bool isOnByDefault);

    void ensureOn();
    void ensureOff();
    bool toggle();
    bool isOn();

    private:

    int relayPin;
    int isOn;
};

#endif