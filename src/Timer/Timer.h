//
// Created by Deep6 on 2017-06-23.
//

#ifndef CONTROL_TIMER_H
#define CONTROL_TIMER_H

class Timer {
    const unsigned long interrupt_time;
    void (*func)();

    public:
        Timer (const unsigned long interrupt_time, void (*func)());
        unsigned long get_time();
        void execute();
};

#endif //CONTROL_TIMER_H
