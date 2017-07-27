#include "JsonHandler.h"
#include <USBAPI.h>

namespace wlp{
	extern JsonHandler json;

    const String JsonHandler::encodeSensor(const String name, const float *sensorData,
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

    const String encodeOneVal(const bool command, const String &name) {
        const size_t BUFFER_SIZE = JSON_OBJECT_SIZE(2) + 40;

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

    const String JsonHandler::encodeCommand(const String commandName) const{
        return encodeOneVal(true, commandName);
    }

    const String JsonHandler::encodeMessage(const String message) const{
        return encodeOneVal(false, message);
    }

	const std::pair<String, int> JsonHandler::decodeCommand(String command){
		const int BUFFER_SIZE = JSON_OBJECT_SIZE(2) + JSON_ARRAY_SIZE(1) + 40;
		StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
		JsonObject &root = jsonBuffer.parseObject(command);

		return {(const char*)root["cmd"], (const int)root["val"][0]};
	}
}
