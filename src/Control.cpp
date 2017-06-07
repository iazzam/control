//
// Created by Deep on 2017-06-06.
// Description: Implementation of Control class
//

#include "Control.h"

// static constants
static const String EMERGENCY = "Emergency Stop";
static const String BRAKE = "Brake";
static const String SPEED = "Speed";
static const String Autonomous = "Autonomous";

Control::Control(int rps, int board_freq, unsigned long bit_rate): rps{rps}, board_freq{board_freq},
                                                                   freq_timer{0}, bit_rate{bit_rate}{}

void Control::setup() {
    // start Serial
    Serial.begin(bit_rate);
}

bool Control::parseCommands(String* json_string) {
    const int BUFFER_SIZE = JSON_OBJECT_SIZE(2) + JSON_ARRAY_SIZE(1);
    StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;

    char json_chars[json_string->length() + 1];
    json_string->toCharArray(json_chars, json_string->length() + 1);

    JsonObject &root = jsonBuffer.parseObject(json_chars);

    if (root.success() && root.containsKey("Command"))
    {
        String command_name = root["Command"];

        if (command_name == EMERGENCY){
            s.is_emergency = root["Value"][0];
        } else if (command_name == Autonomous)
            s.run_autonomous = root["Value"][0];
        else if (command_name == BRAKE)
            s.brake = root["Value"][0];
        else if (command_name == SPEED){
            int speed = root["Value"][0];

            if (speed >= 0 && speed <= 100)
                s.speed_percent = speed;
        } else
            return false;

        return true;
    }

    return false;
}

bool Control::handleReadings() {
    // read from Serial
    String command_str = "";

    if (Serial.available())
        command_str = Serial.readString();

    // parse the commands
    if (command_str != ""){
        return parseCommands(&command_str);
    } else{
        return false;
    }
}

void Control::handleManual() {
    // only allow certain things when there is emergency
    if (!s.is_emergency){

    } else{

    }
}

void Control::handleAutonomous() {
    Serial.println("I am running Autonomous");
}

void Control::loop() {
    if ((freq_timer % (board_freq / rps)) == 0){
        // reset the freq
        freq_timer = 0;

        // read from Serial and update read_status based on that
        bool read_status = handleReadings();

        // only run manual control when there is a command to execute
        if (read_status)
            handleManual();

        // only handle autonomous controls when there is no emergency
        // and we want to run autonomous
        if (!s.is_emergency && s.run_autonomous){
            handleAutonomous();
        }
    }

    ++freq_timer;
}
