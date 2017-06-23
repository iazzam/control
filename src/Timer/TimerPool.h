//
// Created by Deep6 on 2017-06-23.
//

#ifndef CONTROL_TIMERPOOL_H
#define CONTROL_TIMERPOOL_H

#include "Timer.h"
#include "Configurations/Config.h"
#include <Arduino.h>

class TimerPool{
    Timer **timers;
    int counter;

    // timer handling related
    unsigned long *current_micros;

    public:
        TimerPool();

        void addTimer(Timer *t);

        void handleTimers();

        ~TimerPool();
};

#endif //CONTROL_TIMERPOOL_H
