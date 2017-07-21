/*
 * LowPressure.h
 *
 *  Created on: June 17, 2017
 *  Author: Christopher
 *  Description: LowPressure sensor measures the low pressure for Lev system
 */

#ifndef SENSORS_LOWPRESSURE_H
#define SENSORS_LOWPRESSURE_H


#include <Sensor.h>

class LowPressure : public Sensor{
    const uint8_t pin;

    const float MIN_PRESSURE = 100; // TODO: NOT ACCURATE VALUES
    const float MAX_PRESSURE = 200;

    // Gets the low pressure value
    // (0V-5V, 0-1023)
    int getRawPressure();

public:
    LowPressure(const String name, const uint8_t freq, const uint8_t pin);

    // Returns the pressure in ???.
    // Linearly scaled from MIN_PRESSURE to MAX_PRESSURE;
    float read();
};


#endif //SENSORS_LOWPRESSURE_H
