#include "DataHandler.h"

String DataHandler::getJSONString(const String &sensor_name, const float *sensor_data, const int &num_data) {
    const size_t BUFFER_SIZE = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(num_data) + 70;

    DynamicJsonBuffer buffer(BUFFER_SIZE);

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
