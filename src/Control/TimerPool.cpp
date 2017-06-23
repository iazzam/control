//
// Created by Deep on 2017-06-23.
// Description: Implementation of TimePool class and Time class
//

#include "TimerPool.h"


TimerPool::Timer::Timer(const unsigned long interrupt_time, void (*func)()) {
    this->interrupt_time = interrupt_time;
    this->func = func;
}


void TimerPool::Timer::execute() {
    func();
}


unsigned long TimerPool::Timer::get_time() {
    return interrupt_time;
}


TimerPool::TimerPool(const int num_timers) {
    counter = 0;
    this->num_timers = num_timers;
    timers = new Timer*[num_timers];
    most_time = -1;
    most_time_index = -1;
    current_micros = 0;
}


TimerPool::~TimerPool() {
    for (int i = 0; i < num_timers; ++i) {
        delete timers[num_timers];
    }
}


void TimerPool::addTimer(const Timer t) {
    if (counter >= num_timers)
        return;

    timers[counter] = t;

    if (timers[counter]->get_time() > most_time){
        most_time_index = counter;
        most_time = timers[counter];
    }

    // initialize the timer
    Timer1.initialize(most_time);
    Timer1.attachInterrupt(handleTimers);
    current_micros = micros();

    ++counter;
}


void TimerPool::handleTimers() {
    for (int i = 0; i < num_timers; ++i) {
        if (micros - current_micros >= timers[i]->get_time())
            timers[i]->executeFunc();
    }
}
