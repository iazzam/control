//
// Created by Deep6 on 2017-06-23.
//

#include <Arduino.h>
#include "Timer.h"

Timer::Timer(const unsigned long interrupt_time, void (*func)()) : interrupt_time{interrupt_time}, func{func}{}


void Timer::execute() {
    func();
}


unsigned long Timer::get_time() {
    return interrupt_time;
}
