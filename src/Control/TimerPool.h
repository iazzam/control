//
// Created by Deep on 2017-06-23.
// Description: Interface for TimerPool class. This class handles time
//              interrupts for various functions
//

#ifndef CONTROL_TIMER_H
#define CONTROL_TIMER_H

#include <TimerOne.h>

class TimerPool{
    const int num_timers;
    Timer **timers;
    int counter;

    // timer handling related
    unsigned long most_time;
    unsigned long most_time_index;
    unsigned long current_micros;

    void handleTimers();

    public:
        class Timer{
            const unsigned long interrupt_time;
            void (*func)();

            public:
                Timer (const unsigned long interrupt_time, void (*func)());
                unsigned long get_time();
                void execute();
        };

        TimerPool(const int num_timers);

        void addTimer(const Timer t);

        ~TimerPool();
};

#endif //CONTROL_TIMER_H
