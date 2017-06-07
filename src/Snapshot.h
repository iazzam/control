//
// Created by Deep6 on 2017-06-06.
//

#ifndef CONTROL_SNAPSHOT_H
#define CONTROL_SNAPSHOT_H

class Snapshot{
    static int speed = 0;
    static bool is_emergency = false;
    static bool brake = true;
    static float accel_values[] = {0, 0, 0};
    static float gyro_values[] = {0, 0, 0};
    static float mag_values[] = {0, 0, 0};
};

#endif
