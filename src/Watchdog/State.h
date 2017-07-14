#ifndef CONTROL_STATE_H
#define CONTROL_STATE_H

class State {
public:
    // on off states for overall pod functioning
    bool emergency = false;
    bool restart = false;
    bool piCheck = false;
    bool stopped = false;
    bool autonomous = false;
    bool manual = false;
    bool script = true;

    // on off components' states
    bool ballValve = 0;
    bool dpr = 0;
    bool brake;

    // variable components' states
    int speed = 0;

    // board resetting
    bool reset = false;
};


#endif //CONTROL_STATE_H
