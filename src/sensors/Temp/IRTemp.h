/*!
 * @author Deep Dhillon
 * @date July 16, 2017
 * @brief Library for the IR temperature sensor being used
 */

#ifndef SENSORS_IRTEMP_H
#define SENSORS_IRTEMP_H

#include <sensors/Sensor.h>
#include <Adafruit_TMP006.h>

class IRTemp : public Sensor{
private:
    Adafruit_TMP006 tmp006;

public:
	/*!
     * Single constructor creates creates IR temperature sensor
     * @param name sensor name
     * @param freq frequency of the output
     * @param adr address for I2C connection
     */
    IRTemp(const String &name, const uint8_t freq, const uint8_t adr=0x40);

	/*!
     * Reads IR sensor and returns data read from it
     * @return temperature in degree celsius
     */
    float read();
};


#endif //SENSORS_IRTEMP_H
