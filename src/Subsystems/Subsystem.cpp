#include <USBAPI.h>
#include "Subsystem.h"

Subsystem::Subsystem(State* state, WSerial* serial)
        :state{state}, serial{serial} { }

void Subsystem::add(const uint8_t pin) {
    ioPins.push_back(pin);

    pinMode(pin, OUTPUT);
}

void Subsystem::write(const bool state, const uint8_t index) {
    digitalWrite(ioPins[index], state); }

WSerial& Subsystem::getSerial() {
    return *serial;
}

State& Subsystem::getState() {
    return *state;
}
