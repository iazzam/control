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
#include "Sensor.h"


class SensorPool {
    std::vector<Sensor*> sensors;

public:
    /*!
     * Reads all the sensors in pool and discards anything returned by them
     */
    void read();

    /*!
     * Allows for sensors to be added to the pool
     * @param s is the sensor being added
     */
    void add(Sensor *s);

    /*!
     * Gives access to the sensor being stored in the pool. If the sensor is not found,
     * the first sensor in the pool is returned. If no sensor is in the pool, an exception
     * is thrown
     * @param name is the name of sensor
     * @return the sensor with the name specified
     */
    Sensor &get(const String name);

    /*!
     * Gives access to the sensor being stored in the pool. If the index is not found,
     * an exception is thrown
     * @param index is the index of the sensor
     * @return the sensor at the index specified
     */
    Sensor &get(const int index);

    /*!
     * Finds the index based on the name of the sensor. If sensor is not found, -1 is returned
     * @param name is the name of the sensor
     * @return the index of the sensor
     */
    int find(const String name);

    /*!
     * Destroys the pool and frees up the memory
     */
    void destroy();

    friend WSerial &operator <<(WSerial &serial, SensorPool &pool);
};

/*!
 * Prints all the sensors to the serial
 * @param serial is the serial being used
 * @param pool is the pool being used
 * @return the serial
 */
WSerial &operator <<(WSerial &serial, SensorPool &pool);


#endif //SENSORS_SENSORPOOL_H
