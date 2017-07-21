#include "DriveTrain.h"

DriveTrain::DriveTrain(State* state, WSerial* serial)
        :Subsystem(state, serial) { }


void DriveTrain::setup(const uint8_t drivePin1, const uint8_t drivePin2,
        const uint8_t dropPin) {
    add(drivePin1);
    add(drivePin2);
    add(dropPin);
}

void DriveTrain::control(const bool val, Type type) {
    if (type == DRIVE_FRONT){
        write(val, DRIVE_FRONT);
        write(false, DRIVE_BACK);
    } else if (type == DRIVE_BACK){
        write(val, DRIVE_BACK);
        write(false, DRIVE_FRONT);
    } else {
        write(val, DROP);
    }
}
