//
// Created by smishra on 2017-07-08.
//

#ifndef ECBRAKE_ECBRAKE_H
#define ECBRAKE_ECBRAKE_H

#include "Configurations/State.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class ECBrake{
private:
    uint8_t relay;

public:
    void setup(uint8_t relay);
    void control(bool state);
};

#endif //CONTROL_ECBRAKE_H
