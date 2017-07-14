#include "Controller.h"

Controller::Controller(State *s, void(*resetBoard)()) : s{s}, resetBoard{resetBoard}{}


Controller::~Controller(){}


void Controller::setup() {
    serial.begin(bandRate);
    serial << "Setup : " << s->speed << endl;
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

    s->speed += 1;
    Serial.print("Loop: Speed-> ");
    Serial.print(s->speed);
    Serial.print("  Check-> ");
    Serial.println(s->piCheck);
    delay(300);

    if (s->speed % 40 == 0){
        Serial.println("Resetting");
        resetBoard();
    }

}

void Controller::handleAutonomous() {
    /*
     * Autonomous Code here
     */
}

void Controller::control() {
    listener.listen();

    // emergency always has the most priority
    if (s->emergency){
        emergencyProtocol();
        return;
    }

    // restart the pod if there is such a command
    if (s->restart){
        s->restart = false;
        resetBoard();
        return;
    }

    // if pod is stopped call the stop procedure
    if (s->stopped) {
        stop();
        return;
    }

    // choose appropriate mode for running
    if (s->manual){
        handleManual();
    } else if (s->script){
        handleScript();
    } else if (s->autonomous){
        handleAutonomous();
    }
}

void Controller::stop() {
    serial << "Pod Stopped" << endl;
}
