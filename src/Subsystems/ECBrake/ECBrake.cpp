//
// Created by smishra on 2017-07-08.
//

#include <Subsystems/ECBrake/ECBrake.h>

ECBrake::ECBrake(State* state, WSerial* serial)
        :Subsystem(state, serial) { }

void ECBrake::setup(uint8_t relay) {
    add(relay);
}

void ECBrake::control(bool state) {
    write(state);
}
