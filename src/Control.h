//
// Created by Deep on 2017-06-06.
// Description: Interface for Control class. This class holds all pod components together
//              and handles manual and autonomous decisions
//
#ifndef CONTROL_CONTROL_H
#define CONTROL_CONTROL_H

#include <aJSON.h>

class Control{
    private:
        // handleManual() handles all the manual controls for the bot
        void handleManual();
        // handleAutonomous() handles the autonomous bot controls
        void handleAutonomous();

        // parseCommands() parses the commands sent from the control system
        void parseCommands();

    public:
        Control();
        ~Control();

        void setup();
        void loop();
};

#endif
