/*!
 * @name Christopher
 * @date June 17, 2017
 * @brief LowPressure sensor measures the low pressure for Lev System
 */


#ifndef SENSORS_LOWPRESSURE_H
#define SENSORS_LOWPRESSURE_H

#include <sensors/Sensor.h>

class LowPressure : public Sensor{
    const uint8_t pin;

    const float MIN_PRESSURE = 100; // TODO: NOT ACCURATE VALUES
    const float MAX_PRESSURE = 200;

	/*!
	 * Givess access to the raw voltage reading
	 * @return a number from 0 to 1024
	 */
    int getRawPressure();

public:
	/*!
     * Single constructor creates LowPressure sensor
     * @param name name of the sensor
     * @param freq frequency of output
     * @param pin pin to read data from
     */
    LowPressure(const String name, const uint8_t freq, const uint8_t pin);
	
	/*!
     * Reads sensor data from the analog pin and returns scaled values
     * @return the scaled value
     */
    float read();
};


#endif //SENSORS_LOWPRESSURE_H
