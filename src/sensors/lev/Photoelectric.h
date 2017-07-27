/*!
 * @name Christopher
 * @date June 17, 2017
 * @brief Photoelectric sensor measures the distance for Lev System
 */

#ifndef SENSORS_PHOTOELECTRIC_H
#define SENSORS_PHOTOELECTRIC_H


#include <sensors/Sensor.h>

class Photoelectric : public Sensor{
private:
    const uint8_t pin;
    const float MIN_DISTANCE = 20; //millimeters
    const float MAX_DISTANCE = 80;

    /*!
	 * Givess access to the raw voltage reading
	 * @return a number from 0 to 1024
	 */
    int getRawDistance();
public:
    /*!
     * Single constructor creates Photoelectric sensor
     * @param name name of the sensor
     * @param freq frequency of output
     * @param pin pin to read data from
     */
    Photoelectric(const String name, const uint8_t freq, const uint8_t pin);
    
    /*!
     * Reads sensor data from the analog pin and returns scaled values
     * @return the scaled value (distance in millimeters)
     */
    float read();
};


#endif //SENSORS_PHOTOELECTRIC_H
