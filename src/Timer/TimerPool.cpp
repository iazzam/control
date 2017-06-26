//
// Created by Deep6 on 2017-06-23.
//

#include "TimerPool.h"

TimerPool::Timer::Timer(const unsigned long interrupt_time, void (*func)()) :
        interrupt_time{interrupt_time}, func{func}{}


void TimerPool::Timer::execute() {
    func();
}


unsigned long TimerPool::Timer::get_time() {
    return interrupt_time;
}


TimerPool::TimerPool(int num_timers) : counter{0}, num_timers{num_timers}{
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