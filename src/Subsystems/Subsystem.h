#ifndef CONTROL_SUBSYSTEM_H
#define CONTROL_SUBSYSTEM_H

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <Watchdog/State.h>
#include <WSerial.h>
#include <vector>

class Subsystem {
    State *state;
    WSerial *serial;

    std::vector<uint8_t> ioPins;

protected:
    void add(const uint8_t pin);

    void write (const bool state, const uint8_t index = 0);

    Subsystem(State *state, WSerial *serial);

    WSerial &getSerial();
    State &getState();
};

#endif //CONTROL_SUBSYSTEM_H
