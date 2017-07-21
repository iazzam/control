/*
 * Photoelectric.h
 *
 *  Created on: June 17, 2017
 *  Author: Christopher
 *  Description: Photoelectric Sensor used of Levitation
 */

#ifndef SENSORS_PHOTOELECTRIC_H
#define SENSORS_PHOTOELECTRIC_H


#include <Sensor.h>

class Photoelectric : public Sensor{
private:
    const uint8_t pin;
    const float MIN_DISTANCE = 20; //millimeters
    const float MAX_DISTANCE = 80;

    // Gets the distance voltage as measured by the photoelectric distance sensor
    // (0V-5V. 0-1023)
    int getRawDistance();
public:
    Photoelectric(const String name, const uint8_t freq, const uint8_t pin);

    // Returns the distance in millimeters.
    // Linearly scaled from MIN_DISTANCE to MAX_DISTANCE
    float read();
};


#endif //SENSORS_PHOTOELECTRIC_H
