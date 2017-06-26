//
// Created by Deep on 2017-06-06.
// Description: State is the snapshot of various components and their values
//

#ifndef CONTROL_SNAPSHOT_H
#define CONTROL_SNAPSHOT_H

class State{
    public:
        bool board_on = false;

        // components state
        int speed = 0;                  // speed percentage
        bool emergency = false;
        bool brake = true;
        bool run_autonomous = false;
        bool run_manual = false;
        bool run_script = false;


        // lev snapshots
        int lev_state = 0;

};

#endif
