//
// Created by smishra on 2017-07-08.
//

#include <Subsystems/ECBrake/ECBrake.h>

void ECBrake::setup(uint8_t relay) {
    this->relay = relay;
    pinMode(relay,OUTPUT);
}

void ECBrake::control(bool state) {
    if (state) {
        digitalWrite(relay, HIGH);
    } else{
        digitalWrite(relay, LOW);
    }
}