#include <MemoryFree.h>
#include "JSONEncoder.h"


String JSONEncoder::encodeSensor(const String name, const float *sensorData,
                                 const int numData, const int counter) const{
    const size_t BUFFER_SIZE = JSON_OBJECT_SIZE(4) + JSON_ARRAY_SIZE(numData) + 70;

    DynamicJsonBuffer buffer(BUFFER_SIZE);

    JsonObject& sensor = buffer.createObject();
    sensor["time"] = millis();
    sensor["sensor"] = name;

    JsonArray &data = sensor.createNestedArray("data");

    for (int i = 0; i < numData; ++i)
        data.add(sensorData[i]);

    if (counter >= 0)
        sensor["check"] = counter;

    String jsonString;
    sensor.printTo(jsonString);
    return jsonString;
}

String encodeOneVal(const bool command, const String &name) {
    const size_t BUFFER_SIZE = JSON_OBJECT_SIZE(2) + 10;

    DynamicJsonBuffer buffer(BUFFER_SIZE);

    JsonObject& object = buffer.createObject();
    object["time"] = millis();

    if (command)
        object["received"] = name;
    else
        object["message"] = name;

    String jsonString;
    object.printTo(jsonString);
    return jsonString;
}

String JSONEncoder::encodeCommand(const String commandName) const{
    return encodeOneVal(true, commandName);
}

String JSONEncoder::encodeMessage(const String message) const{
    return encodeOneVal(false, message);
}
