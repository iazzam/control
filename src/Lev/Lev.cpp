//
// Created by Christopher on 2017-06-10.
// Description: Implementation of Lev class
//

#include "Lev.h"

Lev::Lev(int relayA, int relayB): relayA{relayA}, relayB{relayB}{
}

void Lev::setup() {
    pinMode(relayA,OUTPUT);
    pinMode(relayB,OUTPUT);
}

/*
void Lev::ballValveControl(int state) {
    if (setState == 1) {
        digitalWrite(relayA, LOW);
        digitalWrite(relayB, HIGH);
        // Needs 6 second delay for valve to open/close, can't let this block
        // delay(6000);
        return 1;
    }

    if (setState == 0) {
        digitalWrite(relayA,HIGH);
        digitalWrite(relayB,LOW);
        // delay(6000);
        return 1;
    }
    return 0;
}*/