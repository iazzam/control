//
// Created by Christopher on 2017-06-10.
// Description: Interface for Levitation class. This class controls lev by sending 
// controls to the ball valve system.
//

#ifndef LEV_LEV_H
#define LEV_LEV_H

#include "Snapshot.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class Lev{
    private:
    	int relayA, relayB;

    public:
        Lev(int relayA, relayB);

        setup();
        control(int state);
};

#endif
