//
// Created by Deep6 on 2017-06-23.
//

#include "TimerPool.h"


TimerPool::TimerPool() : counter{0}{
    timers = new Timer*[num_timers];
    current_micros = new unsigned long[num_timers];
}


TimerPool::~TimerPool() {
    for (int i = 0; i < num_timers; ++i) {
        delete timers[num_timers];
    }
}


void TimerPool::addTimer(Timer *t) {
    if (counter >= num_timers)
        return;

    timers[counter] = t;

    // initialize the timer
    current_micros[counter] = micros();

    ++counter;
}


void TimerPool::handleTimers() {
    for (int i = 0; i < num_timers; ++i) {
        if (micros() - current_micros[i] >= timers[i]->get_time()){
            timers[i]->execute();
            current_micros[i] = micros();
        }
    }
}