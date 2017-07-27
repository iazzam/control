/*!
 * @author Deep Dhillon
 * @date July 12, 2017
 * @brief Library for LM35 contact temperature sensor
 */
#ifndef SENSORS_LM35_H
#define SENSORS_LM35_H


#include <sensors/Sensor.h>

class LM35 : public Sensor{
    const uint8_t pin;

    /*!
     * Reads from analog pin and returns the value
     * @return the voltage value
     */
    int getRawTemp();

public:
    /*!
     * Single constructor creates creates LM35 contact temperature sensor
     * @param name sensor name
     * @param freq frequency of the output
     * @param pin pin for data gathering
     */
    LM35(const String &name, const uint8_t freq, const uint8_t pin);

    /*!
     * Calculates temperature by reading voltage
     * @return the temperature in degree Celsius
     */
    float read();
};


#endif //SENSORS_LM35_H
