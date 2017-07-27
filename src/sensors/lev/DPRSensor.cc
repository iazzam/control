#include <USBAPI.h>
#include "DPRSensor.h"

DPRSensor::DPRSensor(const String name, const uint8_t freq, const uint8_t pin)
        : Sensor{name, freq, 1}, pin{pin}{}

int DPRSensor::getRawDPR() {
    return analogRead(pin);
}

float DPRSensor::read() {
    int scaled = getRawDPR() / 1024 * (MAX_READING - MIN_READING);
    
    add(scaled + MIN_READING);
    return scaled;
}
