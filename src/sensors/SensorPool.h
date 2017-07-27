/*!
 * @author Deep Dhillon
 * @date July 12, 20157
 * @brief Sensor Pool can be used to read write multiple sensors at once. It makes
 *        it easier to deal with a lot of sensors
 */

#ifndef SENSORS_SENSORPOOL_H
#define SENSORS_SENSORPOOL_H

#include <StandardCplusplus.h>
#include <vector>
#include "sensors/Sensor.h"
#include <WSerial.h>

class SensorPool {
    std::vector<Sensor*> sensors;

public:
    /*!
     * Reads all the sensors in pool and discards anything returned by them
     */
    void read();

    /*!
     * Allows for a sensor to be added to the pool
     * @param t is the sensor being added
     */
    void add(Sensor *s);

    /*!
     * Gives access to a sensor in the pool
     * @param index is the index of the sensor
     * @return the element
     */
    Sensor &operator[](const uint8_t index);

    /*!
     * Destroys the pool and frees up the memory
     */
    void destroy();

    friend wlp::WSerial &operator <<(wlp::WSerial &serial, SensorPool &pool);
};

/*!
 * Prints all the sensors/ sensor pools to the serial
 * @param serial is the serial being used
 * @param pool is the pool being used
 * @return the serial
 */
wlp::WSerial &operator <<(wlp::WSerial &serial, SensorPool &pool);


#endif //SENSORS_SENSORPOOL_H
