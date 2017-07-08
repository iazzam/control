#include "Controller.h"
#include <ColorSensor.h>
#include <IMUPool.h>


Controller::Controller(const unsigned long band_rate) : band_rate{band_rate}{}


Controller::~Controller(){
    delete [] received_chars;
}


void Controller::setup() {
    s.board_on = true;
    Serial.begin(band_rate);
    received_chars = new char[max_char];

    ballValve.setup(LEV_RELAY_A, LEV_RELAY_B);
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
            serial << "Hello" << endl;
            if (value < 0 && value > 100) return;

            s.speed = value;
        } else if (name == BALLValve){
            if (value < 0 && value > 1) return;

            s.ballValve = (bool)value;
        }
    }
}


void Controller::readCommand() {
    char curr_char;

    while (Serial.available() > 0 && !new_data) {
        curr_char = (char)Serial.read();

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


void Controller::emergencyProtocol() {

}

void Controller::handleManual() {
    /*
     * Manual Code here
     */
}

void Controller::handleScript() {
    /*
     * Script Code here
     */

    ballValve.control(s.ballValve);
}

void Controller::handleAutonomous() {
    /*
     * Autonomous Code here
     */
}

void Controller::control() {
    // emergency always has the most priority
    if (s.emergency){
        emergencyProtocol();
        return;
    }

    if (s.run_manual){
        handleManual();
    } else if (s.run_script){
        handleScript();
    } else if (s.run_autonomous){
        handleAutonomous();
    }
}
