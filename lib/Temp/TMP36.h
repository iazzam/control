/*!
 * @author Deep Dhillon
 * @date 2017-06-28
 * @brief This class provides library to measure temperature based on TMP36 temperature sensor
 */

#ifndef SENSORS_TMP36_H
#define SENSORS_TMP36_H

#include <Arduino.h>
#include <shared/DataHandler.h>

class TMP36 {
    const String name;      /*!< name of the sensor */
    const uint8_t io_pin;   /*!< pin the sensor is attached too */
    DataHandler handler;    /*!< data handler being used */

public:
    /*!
     * Single constructor initializes the sensor and setups an analog connection
     * @param name is the name of the sensor
     * @param io_pin is the pin this sensor is attached too
     */
    TMP36(const String name, const uint8_t io_pin);

    // serialPrint() prints temp data to the Serial
    /*!
     * Prints temperature data to the Serial
     */
    void serialPrint();

    /*!
     * Gives access to temperature
     * @return the updated temperature
     */
    float getTemp() const;
};


#endif //SENSORS_TMP36_H
