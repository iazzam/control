#include "Controller.h"

Controller::Controller(State *s, void(*resetBoard)(bool), JSONEncoder *encoder, WSerial *serial)
        : s{s}, resetBoard{resetBoard}, encoder{encoder}, serial{serial}{
    listener = new CommandListener{s, encoder, serial};
}


Controller::~Controller(){
    delete listener;
}


void Controller::setup() {
}

void Controller::emergencyProtocol() {
    *serial << encoder->encodeMessage("Pod in Emergency") << endl;

    stop();
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
}

void Controller::handleAutonomous() {
    /*
     * Autonomous Code here
     */
}

void Controller::control() {
    listener->listen();

    // do not do anything unless you are connected;
    if (!s->connect) return;

    // emergency always has the most priority
    if (s->emergency){
        emergencyProtocol();
        return;
    }


    // restart the pod if there is such a command
    if (s->restartSaved){
        s->restartSaved = false;
        resetBoard(true);
        return;
    } else if (s->restartUnsaved){
        s->restartUnsaved = false;
        resetBoard(false);
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

void Controller::check() {
    // do not do anything unless you are connected or pod is stopped
    if (!s->connect || s->stopped) return;

    if (s->piCheck){
        heartBeatMiss = 0;
        s->piCheck = false;
    } else if (heartBeatMiss >= 2){
        *serial << encoder->encodeMessage("Check missed stopping the pod") << endl;
        s->stopped = true;
    } else ++heartBeatMiss;
}

void Controller::stop() {
    *serial << encoder->encodeMessage("Pod Stopped") << endl;
}

