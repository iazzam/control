#include "LevDPR.h"

void LevDPR::setup(uint8_t relayA) {
    this->relayA = relayA;

    pinMode(relayA,OUTPUT);
}

void LevDPR::control(bool state) {
    if (state) {
        digitalWrite(relayA, HIGH);
    } else{
        digitalWrite(relayA, LOW);
    }
}