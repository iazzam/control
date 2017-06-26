/*
 * IMUData.h
 *
 *  Created on: May 25, 2017
 *  Author: Deep Dhillon
 *  Description: DataHandler handles sensor data and provides various methods
 *               to handle that data
 */

#ifndef SRC_IMUDATA_H_
#define SRC_IMUDATA_H_

#include "ArduinoJson.h"
#include <Arduino.h>

class DataHandler {
    public:
        // getJSONString() creates and returns a JSON string from the particular sensor
        String getJSONString(String sensor_name, float *sensor_data, int num_data);
};

#endif
