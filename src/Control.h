//
// Created by Deep on 2017-06-06.
// Description: Interface for Control class. This class holds all pod components together
//              and handles manual and autonomous decisions
//
#ifndef CONTROL_CONTROL_H
#define CONTROL_CONTROL_H

#include "Snapshot.h"
#include "Lev.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class Control{
    private:
        // board variables
        int rps;
        long board_freq;
        int freq_timer;
        const unsigned long bit_rate;

        // to measure loop speed
        unsigned long start_time;
        int curr_frames;
        int last_frames;

        Snapshot s;
        Lev lev;

        // handleManual() handles all the manual controls for the bot
        void handleManual();
        // handleAutonomous() handles the autonomous bot controls
        void handleAutonomous();
        // handleReadings() handles the reading and parsing of data
        bool handleReadings();
        // parseCommands() parses the commands sent from the control system
        bool parseCommands(String* json_string);

    public:
        Control(int rps, long board_freq, unsigned long bit_rate);

        void setup();
        void loop();
        int getRps();
};

#endif
