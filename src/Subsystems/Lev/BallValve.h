//
// Created by Christopher on 2017-06-10.
// Description: Interface for Levitation class. This class controls lev by sending 
// controls to the ball valve system.
//

#ifndef LEV_LEV_H
#define LEV_LEV_H

#include "Watchdog/State.h"
#include <ArduinoJson.h>
#include <Subsystems/Subsystem.h>

class BallValve : Subsystem{
    public:
        BallValve(State* state, WSerial* serial);

        void setup(uint8_t relayA, uint8_t relayB);

        void control(bool state);
};

#endif
