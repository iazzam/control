//
// Created by Deep on 2017-06-06.
// Description: Implementation of Control class
//

#include "Control.h"

Control::Control() : EMERGENCY {"Emergency Stop"}, BRAKE {"Brake"}, SPEED {"Speed"} {}

Control::~Control() {}

void Control::parseCommands(String* json_string) {
    const int BUFFER_SIZE = JSON_OBJECT_SIZE(2) + JSON_ARRAY_SIZE(1);
    StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;

    char json_chars[json_string->length() + 1];
    json_string->toCharArray(json_chars, json_string->length() + 1);

    JsonObject &root = jsonBuffer.parseObject(json_chars);

    if (root.success() && root.containsKey("Command"))
    {
        String command_name = root["Command"];

        if (command_name == EMERGENCY){
            s.is_emergency = true;
            s.brake = true;
        }
        else if (command_name == BRAKE)
            s.brake = true;
        else if (command_name == SPEED){
            int speed = root["Value"][0];

            if (speed >= 0 && speed <= 100)
                s.speed_percent = speed;
        }
    }
}

void Control::loop() {
    // read from Serial
    String command_str = Serial.readString();

    if (command_str != ""){
        parseCommands(&command_str);

        Serial.print("Emergency: ");
        Serial.println(s.is_emergency);

        while (1){

        }
    }
}
