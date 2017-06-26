/*
 * IMUData.cpp
 *
 *  Created on: May 25, 2017
 *  Author: Deep Dhillon
 *  Description: Implementation of DataHandler class
 */

#include "DataHandler.h"

String DataHandler::getJSONString(String sensor_name, float *sensor_data, int num_data) {
    const int BUFFER_SIZE = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(3) + 70;

    StaticJsonBuffer <BUFFER_SIZE> buffer;

    JsonObject& sensor = buffer.createObject();
    sensor["time"] = millis();
    sensor["sensor"] = sensor_name;

    JsonArray &data = sensor.createNestedArray("data");

    for (int i = 0; i < num_data; ++i) {
        data.add(sensor_data[i]);
    }

    String json_string;
    sensor.printTo(json_string);
    return json_string;
}
