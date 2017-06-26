//
// Created by Deep on 2017-06-25.
// Description: This is the main file that will run everything and will
//              manage subsystems using controller
//

#include <Arduino.h>
#include <Timer/TimerPool.h>
#include <Configurations/Config.h>
#include "Controller.h"

TimerPool pool{num_timers};
Controller c{band_rate};

// will handle reading of commands
void readCommands(){
    c.handleCommands();
}

// will make decisions and run everything
void execute(){
    c.control();
}

void setup(){
    // add timers
    pool.addTimer(new TimerPool::Timer(parse_rate, readCommands));
    pool.addTimer(new TimerPool::Timer(execute_rate, execute));

    // setup the controller
    c.setup();
}

void loop(){
    pool.handleTimers();
}
