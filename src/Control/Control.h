//
// Created by Deep on 2017-06-06.
// Description: Interface for Control class. This class holds all pod components together
//              and handles manual and autonomous decisions
//
#ifndef CONTROL_CONTROL_H
#define CONTROL_CONTROL_H

#include "Configurations/Snapshot.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include "../Shared/Config.h"
#include "Control/Timer/TimerPool.h"

class Control{
    private:
        bool board_on;

        TimerPool pool;
        Snapshot s;
        //Lev lev;

        // handleManual() handles all the manual controls for the bot
        void handleManual();
        // handleAutonomous() handles the autonomous bot controls
        void handleAutonomous();
        // handleReadings() handles the reading and parsing of data
        bool handleReadings();
        // parseCommands() parses the commands sent from the control system
        bool parseCommands(String* json_string);

        void readSensors();
        void readCommands();
        void execute();

    public:
        Control();

        void start();
        int getRps();
};

#endif
