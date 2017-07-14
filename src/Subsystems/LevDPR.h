#ifndef _DPR_H
#define _DPR_H


#include <Arduino.h>

class LevDPR {
private:
    uint8_t relayA;

public:
    void setup(uint8_t relayA);
    void control(bool state);
};


#endif //_DPR_H
