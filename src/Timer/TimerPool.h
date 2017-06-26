//
// Created by Deep on 2017-06-23.
// Description: TimerPool provides a pool of timers to execute different
//              functions at different times
//

#ifndef CONTROL_TIMERPOOL_H
#define CONTROL_TIMERPOOL_H

#include <Arduino.h>

class TimerPool{
    public:
        struct Timer{
        private:
            const unsigned long interrupt_time;
            void (*func)();

        public:
            Timer (const unsigned long interrupt_time, void (*func)());
            unsigned long get_time();
            void execute();
        };

        TimerPool(int num_timers);

        // addTimer() adds given timer to the pool
        void addTimer(Timer *t);

        // handleTimers() updates times for pool to keep them in sync
        void handleTimers();

        ~TimerPool();

    private:
        Timer **timers;
        int counter;
        const int num_timers;
        unsigned long *current_micros;

};

#endif //CONTROL_TIMERPOOL_H
