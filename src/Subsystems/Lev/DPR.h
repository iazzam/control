#ifndef _DPR_H
#define _DPR_H


#include <Subsystems/Subsystem.h>

class DPR : Subsystem{
public:
    DPR(State* state, WSerial* serial);

    void setup(uint8_t relayA);

    void control(bool state);
};


#endif //_DPR_H
