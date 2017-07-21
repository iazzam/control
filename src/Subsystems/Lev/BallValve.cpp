//
// Created by Christopher on 2017-06-10.
// Description: Implementation of BallValve class
//

#include "BallValve.h"

BallValve::BallValve(State* state, WSerial* serial)
        :Subsystem(state, serial) { }

void BallValve::setup(uint8_t relayA, uint8_t relayB) {
    add(relayA);
    add(relayB);
}

void BallValve::control(bool state) {
    if (state) {
        write(0, LOW);
        write(1, HIGH);
    } else{
        write(0, HIGH);
        write(1, LOW);
    }
}

