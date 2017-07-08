/*!
 * @author Deep Dhillon
 * @date 2017-05-25
 * @brief This class handles sensor data and provides methods to manipulate data
 */

#ifndef SRC_IMUDATA_H_
#define SRC_IMUDATA_H_

#include <ArduinoJson.h>
#include <Arduino.h>

class DataHandler {
public:
    /*!
     * Creates a JSON String from the data provided
     * @param sensor_name name of the sensor from which data is obtained
     * @param sensor_data an array of data points
     * @param num_data  number of data points in the array
     * @return data formatted in JSON String
     */
    String getJSONString(const String &sensor_name, const float *sensor_data, const int &num_data);
};

#endif
