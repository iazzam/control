#ifndef CONTROL_DRIVETRAIN_H
#define CONTROL_DRIVETRAIN_H

#include <Subsystems/Subsystem.h>

class DriveTrain : Subsystem{
public:
    enum Type{
      DRIVE_FRONT = 0,
      DRIVE_BACK = 1,
      DROP = 2
    };

    DriveTrain(State* state, WSerial* serial);

    void setup(const uint8_t drivePin1, const uint8_t drivePin2, const uint8_t dropPin);

    void control(const bool val, Type type);
};

#endif //CONTROL_DRIVETRAIN_H
