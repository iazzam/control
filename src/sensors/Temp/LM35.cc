#include <USBAPI.h>
#include "LM35.h"

LM35::LM35(const String &name, const uint8_t freq, const uint8_t pin)
        : Sensor{name, freq, 1}, pin{pin}{}

int LM35::getRawTemp() {
    return analogRead(pin);
}

float LM35::read() {
    float temp = (5.0 * getRawTemp() * 100.0) / MAX_ANALOG;

    add(temp);
    return temp;
}
