#include "LowPressure.h"

LowPressure::LowPressure(const String name, const uint8_t freq, const uint8_t pin)
        : Sensor{name, freq, 1}, pin{pin}{}

int LowPressure::getRawPressure() {
    return analogRead(pin);
}

float LowPressure::read() {
    float scaled = getRawPressure() / 1024.0 * (MAX_PRESSURE - MIN_PRESSURE);

    add(scaled + MIN_PRESSURE);
    return get(0);
}
