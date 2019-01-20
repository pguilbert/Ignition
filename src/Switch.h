#ifndef Switch_h
#define Switch_h

#include <Bounce2.h>

class Switch {
    Switch(int switchPin, int pressedSwitchPinValue = LOW);

    void update();

    bool justPressed();
    bool justReleased();
    bool isPressed();

    int switchPin;
    bool hasPinInputPullUp;
    Bounce debouncer;
};

#endif