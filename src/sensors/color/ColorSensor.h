#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <sensors/Sensor.h>

class ColorSensor : public Sensor{
    const uint8_t out1Pin;
    const uint8_t out2Pin;
    const uint8_t out3Pin;

    /*!
     * Restricts the value to 0 if under the bound and 1 if over
     * @param value is the value of then sensor being provided
     * @param bound is the bound to be checked
     * @return 0 or 1
     */
    uint8_t limit(const int value, const int bound);

public:
    /*!
     * Single constructor creates a Color sensor
     * @param name sensor name
     * @param freq frequency of output
     * @param ou1Pin input pin 1
     * @param out2Pin input pin 2
     * @param out3Pin input pin 3
     */
    ColorSensor(const String name, const uint8_t freq, const uint8_t ou1Pin,
                const uint8_t out2Pin, const uint8_t out3Pin);

    /*!
     * Gives access to the value read from input 1
     * @return input 1 values
     */
    uint8_t getOut1();

    /*!
     * Gives access to the value read from input 2
     * @return input 2 values
     */
    uint8_t getOut2();

    /*!
     * Gives access to the value read from input 3
     * @return input 3 values
     */
    uint8_t getOut3();

    /*!
     * Gives access to the overall final reading of the sensor
     * @return a value from 0 to 7
     */
    float read();
};

#endif
