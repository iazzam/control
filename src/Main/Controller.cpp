//
// Created by Deep6 on 2017-06-25.
//

#include "Controller.h"

Controller::Controller(const unsigned long band_rate) : band_rate{band_rate}{}


Controller::~Controller(){
    delete [] received_chars;
}


void Controller::setup() {
    Serial.begin(band_rate);
    received_chars = new char[max_char];
}


int getValue(JsonObject &root){
    return root["val"][0];
}

void Controller::parseCommand(String command) {
    const int BUFFER_SIZE = JSON_OBJECT_SIZE(2) + JSON_ARRAY_SIZE(1) + 40;
    StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(command);

    if (root.success() && root.containsKey("cmd") && root.containsKey("val")){
        String name = root["cmd"];
        int value = getValue(root);

        if (name == EMERGENCY){
            if (value < 0 && value > 1) return;
            s.emergency = (bool)value;
        }
        else if (name == AUTONOMOUS){
            if (value < 0 && value > 1) return;
            s.run_autonomous = (bool)value;
            s.run_manual = false;
            s.run_script = false;
        }
        else if (name == MANUAL){
            if (value < 0 && value > 1) return;
            s.run_manual = (bool)value;
            s.run_script = false;
            s.run_autonomous = false;
        }
        else if (name == SCRIPT){
            if (value < 0 && value > 1) return;
            s.run_script = (bool)value;
            s.run_manual = false;
            s.run_autonomous = false;
        }
        else if (name == BRAKE){
            if (value < 0 && value > 1) return;
            s.brake = (bool)value;
        }
        else if (name == SPEED){
            if (value < 0 && value > 100) return;
            s.speed = value;
        }
    }
}


void Controller::readCommand() {
    char curr_char;

    while (Serial.available() > 0 && !new_data) {
        curr_char = Serial.read();

        if (reading) {
            if (curr_char != end_marker) {
                received_chars[char_index] = curr_char;
                ++char_index;

                // in case of overflow
                if (char_index >= max_char)
                    char_index = max_char - 1;
            } else {
                received_chars[char_index] = curr_char;
                ++char_index;
                received_chars[char_index] = '\0'; // terminate the string
                reading = false;
                char_index = 0;
                new_data = true;
            }
        } else if (curr_char == start_marker) {
            received_chars[char_index] = curr_char;
            ++char_index;
            reading = true;
        }
    }
}


void Controller::handleCommands() {
    // read command if available
    readCommand();

    // parse the command and set flags
    if (new_data){
        parseCommand(received_chars);
        new_data = false;
    }
}


void Controller::emergency_protocol() {
    /*
     * Emergency Code here
     */
    exit(1);
}

void Controller::handle_manual() {
    /*
     * Manual Code here
     */
}

void Controller::handle_script() {
    /*
     * Script Code here
     */
}

void Controller::handle_autonomous() {
    /*
     * Autonomous Code here
     */
}

void Controller::control() {
    // emergency always has the most priority
    if (s.emergency){
        emergency_protocol();
        return;
    }

    if (s.run_manual){
        handle_manual();
    } else if (s.run_script){
        handle_script();
    } else if (s.run_autonomous){
        handle_autonomous();
    }
}
