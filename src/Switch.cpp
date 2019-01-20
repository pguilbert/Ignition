#include "Switch.h"

Switch::Switch(int switchPin, int pressedSwitchPinValue) : 
    switchPin(switchPin),
    hasPinInputPullUp(pressedSwitchPinValue == LOW),
    debouncer(Bounce())
{
    debouncer.attach(this->switchPin);
    debouncer.interval(20);
};

void Switch::update() {
    debouncer.update();
}

bool Switch::justPressed() {
    return this->hasPinInputPullUp ? debouncer.fell() : debouncer.rose();
}

bool Switch::justReleased() {
    return this->hasPinInputPullUp ? debouncer.rose() : debouncer.fell();
}

bool Switch::isPressed() {
    return (this->hasPinInputPullUp && !debouncer.read()) || (!this->hasPinInputPullUp && debouncer.read());
}
