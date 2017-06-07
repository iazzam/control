//
// Created by Deep on 2017-06-06.
// Description: Snapshot holds the various variables related to pod
//

#ifndef CONTROL_SNAPSHOT_H
#define CONTROL_SNAPSHOT_H

class Snapshot{
    public:
        // control logic values
        int speed_percent = 0;
        bool is_emergency = false;
        bool brake = true;
};

#endif
