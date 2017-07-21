#include <Watchdog/State.h>
#include "MagWheels.h"

MagWheels::MagWheels(State* state, WSerial* serial)
        :Subsystem(state, serial) { }


void MagWheels::setup(uint8_t flp, uint8_t frp, uint8_t rlp, uint8_t rrp) {
    flServo.attach(flp);
    frServo.attach(frp);
    rlServo.attach(rlp);
    rrServo.attach(rrp);

    // calibrate
    flServo.writeMicroseconds(2000);
    flServo.writeMicroseconds(1000);

    frServo.writeMicroseconds(2000);
    frServo.writeMicroseconds(1000);

    rlServo.writeMicroseconds(2000);
    rlServo.writeMicroseconds(1000);

    rrServo.writeMicroseconds(2000);
    rrServo.writeMicroseconds(1000);

    lastSpeed = 0;
}
void MagWheels::control(uint8_t speed) {
    if (!getState().magSpeedChanged) return;

    if (lastSpeed >= speed){
        for (int i = lastSpeed; i >= speed; --i) {
            int val = map(i, 0, 100, 1000, 2000);

            //Serial.println(val);

            flServo.writeMicroseconds(val);
            frServo.writeMicroseconds(val);
            rlServo.writeMicroseconds(val);
            rrServo.writeMicroseconds(val);
            delay(7);
        }
    } else{
        for (int i = lastSpeed; i <= speed; ++i) {
            int val = map(i, 0, 100, 1000, 2000);

            flServo.writeMicroseconds(val);
            frServo.writeMicroseconds(val);
            rlServo.writeMicroseconds(val);
            rrServo.writeMicroseconds(val);
            delay(7);
        }
    }

    lastSpeed = speed;

    getState().magSpeedChanged = false;
}

