#include "IRTemp.h"

IRTemp::IRTemp(const String& name, const uint8_t freq, const uint8_t adr)
        : Sensor{name, freq, 1}, tmp006{adr} {
    tmp006.begin();
    tmp006.wake();
}

float IRTemp::read() {
    float temp = tmp006.readDieTempC();

    add(temp);

    return temp;
}


