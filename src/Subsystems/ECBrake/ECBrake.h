//
// Created by smishra on 2017-07-08.
//

#ifndef ECBRAKE_ECBRAKE_H
#define ECBRAKE_ECBRAKE_H

#include "Watchdog/State.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Subsystems/Subsystem.h>

class ECBrake : Subsystem{
public:
    ECBrake(State* state, WSerial* serial);

    void setup(uint8_t relay);
    void control(bool state);
};

#endif //CONTROL_ECBRAKE_H
