#ifndef Switch_h
#define Switch_h

#include <Bounce2.h>

class Switch {
    Switch(int switchPin);

    bool justPressed();
    bool justReleased();
    bool isPressed();

    int switchPin;
    int outputToswitchPin;
    Bounce debouncer;
};

#endif