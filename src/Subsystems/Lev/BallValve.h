//
// Created by Christopher on 2017-06-10.
// Description: Interface for Levitation class. This class controls lev by sending 
// controls to the ball valve system.
//

#ifndef LEV_LEV_H
#define LEV_LEV_H

#include "Watchdog/State.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class BallValve{
    private:
    	uint8_t relayA, relayB;

    public:
        void setup(uint8_t relayA, uint8_t relayB);
        void control(bool state);
};

#endif
