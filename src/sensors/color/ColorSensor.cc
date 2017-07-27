#include <USBAPI.h>
#include "ColorSensor.h"

ColorSensor::ColorSensor(const String name, const uint8_t freq, const uint8_t ou1Pin,
                         const uint8_t out2Pin, const uint8_t out3Pin)
        : Sensor{name, freq, 1}, out1Pin{ou1Pin}, out2Pin{out2Pin}, out3Pin{out3Pin} {}


uint8_t ColorSensor::limit(const int value, const int bound) {
    if (value >= bound) return 1;
    else return 0;
}


uint8_t ColorSensor::getOut1() {
    //Limiting outputs to 0 & 1, instead of 0 - 1023
    return limit(analogRead(out1Pin), 1000);
}


uint8_t ColorSensor::getOut2() {
    //Limiting outputs to 0 & 1, instead of 0 - 1023
    return limit(analogRead(out2Pin), 1000);
}


uint8_t ColorSensor::getOut3() {
    //Limiting outputs to 0 & 1, instead of 0 - 1023
    return limit(analogRead(out3Pin), 1000);
}


float ColorSensor::read() {
    uint8_t out1 = getOut1();
    uint8_t out2 = getOut2();
    uint8_t out3 = getOut3();

    // 0 is background (black, dark_blue)
    if (out1 == 0 && out2 == 0 && out3 == 0) add(0);

    // 1 is Red, brown, pinkish-red, orange
    else if (out3 == 0 && out2 == 0 && out1 == 1) add(1);

    // 2 is Yellow, orange
    else if (out3 == 0 && out2 == 1 && out1 == 0) add(2);
    else if (out3 == 0 && out2 == 1 && out1 == 1) add(3);

    // 4 is White,
    else if (out3 == 1 && out2 == 0 && out1 == 0) add(4);
    else if (out3 == 1 && out2 == 0 && out1 == 1) add(5);
    else if (out3 == 1 && out2 == 1 && out1 == 0) add(6);
    else if (out3 == 1 && out2 == 1 && out1 == 1) add(7);

    return get(0);
}
