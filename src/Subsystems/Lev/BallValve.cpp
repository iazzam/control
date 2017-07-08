//
// Created by Christopher on 2017-06-10.
// Description: Implementation of BallValve class
//

#include "BallValve.h"

void BallValve::setup(uint8_t relayA, uint8_t relayB) {
    this->relayA = relayA;
    this->relayB = relayB;

    pinMode(relayA,OUTPUT);
    pinMode(relayB,OUTPUT);
}

void BallValve::control(bool state) {
    if (state) {
        digitalWrite(relayA, LOW);
        digitalWrite(relayB, HIGH);
    } else{
        digitalWrite(relayA, HIGH);
        digitalWrite(relayB, LOW);
    }
}