#include "DPR.h"

DPR::DPR(State* state, WSerial* serial)
        :Subsystem(state, serial) { }

void DPR::setup(uint8_t relayA) {
    add(relayA);
}

void DPR::control(bool state) {
    write(state);
}

