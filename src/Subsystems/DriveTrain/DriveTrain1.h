#ifndef CONTROL_DRIVETRAIN_H
#define CONTROL_DRIVETRAIN_H

#include <Watchdog/State.h>
#include "Arduino.h"

class DriveTrain1 {
private:
    uint8_t motorRelayPin;
    uint8_t solanoidRelayPin;
    State *s;
public:
    void setup(uint8_t motorRelayPin, uint8_t solanoidRelayPin, State *s);
    void controlSolonoid(bool state);
    void controlDriver(bool state);
};


#endif //CONTROL_DRIVETRAIN_H
