#include <USBAPI.h>
#include "Photoelectric.h"

Photoelectric::Photoelectric(const String name, const uint8_t freq, const uint8_t pin)
        : Sensor(name, freq, 1), pin{pin} {}

int Photoelectric::getRawDistance() {
    return analogRead(pin);
}

float Photoelectric::read() {
    float scaled = getRawDistance() / 1024.0 * (MAX_DISTANCE - MIN_DISTANCE);
    add(scaled + MIN_DISTANCE);

    return get(0);
}
