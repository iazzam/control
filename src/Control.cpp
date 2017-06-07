//
// Created by Deep on 2017-06-06.
// Description: Implementation of Control class
//

#include "Control.h"

Control::Control() {}

Control::~Control() {}

void Control::parseCommands(char* json_string) {
    aJsonObject* stringObject = aJson.parse(json_string);
}
