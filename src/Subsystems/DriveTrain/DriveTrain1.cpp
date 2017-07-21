#include "DriveTrain1.h"

void DriveTrain1::setup(uint8_t motorRelayPin, uint8_t solanoidRelayPin, State *s) {
    this->motorRelayPin = motorRelayPin;
    this->solanoidRelayPin = solanoidRelayPin;
    this->s = s;

    pinMode(motorRelayPin, OUTPUT);
    pinMode(solanoidRelayPin, OUTPUT);

}

void DriveTrain1::controlSolonoid(bool state) {
    digitalWrite(solanoidRelayPin, state);
    s->eDropChanged = false;
}

void DriveTrain1::controlDriver(bool state) {
    s->eDriveChanged = false;
    digitalWrite(motorRelayPin, state);
}
