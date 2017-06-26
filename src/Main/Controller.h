//
// Created by Deep on 2017-06-25.
// Description: Controller is used to control the pod and will provide for an
//              interface to make everything work
//

#ifndef CONTROL_POD_CONTROLLER_H
#define CONTROL_POD_CONTROLLER_H

#include <HardwareSerial.h>
#include <ArduinoJson.h>
#include <Configurations/State.h>
#include <Configurations/Config.h>

class Controller {
    // Serial fields
    const unsigned long band_rate;

    // Reading JSON Strings fields
    const int max_char = 100;
    char *received_chars;
    bool new_data = false;
    bool reading = false;
    int char_index = 0;
    char start_marker = '{';
    char end_marker = '}';

    // state of the pod
    State s;

    // readCommand() reads characters from the Serial and makes a String
    void readCommand();

    // parseCommand() parses JSON string and set flags
    void parseCommand(String command);

    // emergency_protocol() handles the case when there is emergency
    void emergency_protocol();

    // handle_manual() handles the case where the pod is in manual control
    void handle_manual();

    // handle_script() handles the case where the pod will function on predefined script
    void handle_script();

    // handle_autonomous() handles the case where the pod will function autonomously
    void handle_autonomous();
public:
    Controller(const unsigned long band_rate);
    ~Controller();

    // setup() initializes the controller
    void setup();

    // handleCommands() will parse commands received from Serial
    void handleCommands();

    // control() will handle the overall control of the pod
    void control();
};


#endif //CONTROL_POD_CONTROLLER_H
