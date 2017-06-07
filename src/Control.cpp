//
// Created by Deep on 2017-06-06.
// Description: Implementation of Control class
//

#include "Control.h"

Control::Control() {}

Control::~Control() {}

void Control::parseCommands(char* json_string) {
    aJsonObject* stringObject = aJson.parse(json_string);

    String name = aJson.getObjectItem(stringObject, "Command")->valuestring;

    if (name == EMERGENCY){
        s.is_emergency = true;
        s.brake = true;
    }
    else if (name == BRAKE)
        s.brake = true;
    else if (name == SPEED){
        int speed = aJson.getObjectItem(stringObject, "Value")->valueint;

        if (speed >= 0 && speed <= 100)
            s.speed_percent = speed;
    }

}

void Control::loop() {
    // read from Serial
    char *command_char;
    String command_str = Serial.readString();

    command_str.toCharArray(command_char, command_str.length());

    parseCommands(command_char);
}
