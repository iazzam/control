#ifndef CONTROL_STATE_H
#define CONTROL_STATE_H

#include <stdint.h>

class State {
public:
    // connection with pi
    bool connect = false;
    bool piCheck = false;
    
    // on off states for overall pod functioning
    bool emergency = false;
    bool restartSaved = false;
    bool restartUnsaved = false;
    bool stopped = false;
    bool autonomous = false;
    bool manual = false;
    bool script = false;

    // on off components' states
    bool ballValve = 0;
    bool dpr = 0;
    bool brake;

    // variable components' states
    uint8_t speed = 0;

    // board resetting
    bool reset = false;
};


#endif //CONTROL_STATE_H
