/*!
 * @author Deep Dhillon
 * @date 2017-06-28
 * @brief This class provides library to measure temperature based on TMP36 temperature sensor
 */

#ifndef SENSORS_TMP36_H
#define SENSORS_TMP36_H

#include <Sensor.h>

class TMP36 : public Sensor{
    const uint8_t pin;   /*!< pin the sensor is attached too */

    /*!
     * Reads from analog pin and returns the value
     * @return the voltage value
     */
    int getRawTemp();

public:
    TMP36(const String name, const uint8_t freq, const uint8_t pin);

    /*!
     * Calculates temperature by reading voltage. The temperature is in degree
     * Celsius
     * @return the temperature in degree Celsius
     */
    float read();
};


#endif //SENSORS_TMP36_H
