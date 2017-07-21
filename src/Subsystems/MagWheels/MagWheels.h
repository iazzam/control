#ifndef CONTROL_MAGWHEELS_H
#define CONTROL_MAGWHEELS_H

#include <avr/io.h>
#include <Servo.h>
#include <Subsystems/Subsystem.h>

class MagWheels : Subsystem{
    // servos for each motor
    Servo flServo;
    Servo frServo;
    Servo rlServo;
    Servo rrServo;

    int lastSpeed;

public:
    MagWheels(State* state, WSerial* serial);

    void setup(uint8_t flp, uint8_t frp, uint8_t rlp, uint8_t rrp);

    void control(uint8_t speed);
};

#endif //CONTROL_MAGWHEELS_H
