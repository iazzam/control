/*!
 * @author Deep Dhillon
 * @date June 26, 2017
 * @brief This class provides library to measure temperature based on TMP36 temperature sensor
 */

#ifndef SENSORS_TMP36_H
#define SENSORS_TMP36_H

#include <sensors/Sensor.h>

class TMP36 : public Sensor{
    const uint8_t pin;

    /*!
     * Reads from analog pin and returns the value
     * @return the voltage value
     */
    int getRawTemp();

public:
    /*!
     * Single constructor creates creates TMP36 contact temperature sensor
     * @param name sensor name
     * @param freq frequency of the output
     * @param pin pin for data gathering
     */
    TMP36(const String name, const uint8_t freq, const uint8_t pin);

    /*!
     * Calculates temperature by reading voltage
     * @return the temperature in degree Celsius
     */
    float read();
};


#endif //SENSORS_TMP36_H
