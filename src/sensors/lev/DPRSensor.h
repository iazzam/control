/*!
 * @author Deep Dhillon
 * @date July 12 2017
 * @brief DPR sensor for Levitation which signals if DPR is on or off
 */

#ifndef SENSORS_DPRSENSOR_H
#define SENSORS_DPRSENSOR_H

#include <sensors/Sensor.h>

class DPRSensor : public Sensor{
    const uint8_t pin;
    const uint8_t MAX_READING = 1;
    const uint8_t MIN_READING = 0;
    
    /*!
     * Givess access to the raw voltage reading
     * @return a number from 0 to 1024
     */
    int getRawDPR();
public:
    /*!
     * Single constructor creates DPR sensor
     * @param name name of the sensor
     * @param freq frequency of output
     * @param pin pin to read data from
     */
    DPRSensor(const String name, const uint8_t freq, const uint8_t pin);

    /*!
     * Reads sensor data from the analog pin and returns scaled values
     * @return the scaled value
     */
    float read();
};


#endif //SENSORS_DPRSENSOR_H
