#include "Controller.h"

Controller::Controller(State *s, void(*resetBoard)(bool), 
        JSONEncoder *encoder, WSerial *serial, Config *config)
        : s{s}, resetBoard{resetBoard}, encoder{encoder}, serial{serial}, config{config}{
    listener = new CommandListener{s, encoder, serial, config};
}


Controller::~Controller(){
    delete listener;
}


void Controller::setup() {
    wheels = new MagWheels{s, serial};
}

void Controller::emergencyProtocol() {
    stop();
}

void Controller::handleManual() {
    wheels->control(s->speedMag);
}

void Controller::handleScript() {
    *serial << "SS" << endl;
    /*
     * Script Code here
     */
}

void Controller::handleAutonomous() {
    *serial << "AA" << endl;
    /*
     * Autonomous Code here
     */
}

void Controller::handleRestart(){
    if (s->currentRestart == State::RESTARTS){
        resetBoard(true);
    } else if (s->currentRestart == State::RESTARTUS){
        resetBoard(false);
    }
}

void Controller::useCurrentConnection() {
    if (s->currentConnection == State::CONNECTED){
        if (s->currentRestart != State::NONE)
            handleRestart();
        else
            useCurrentFuncState();
    }
}

void Controller::useCurrentFuncState() {
    if (s->currentFuncState == State::EMERGENCY){
        emergencyProtocol();
    } else if (s->currentFuncState == State::STOP){
        stop();
    } else if (s->currentFuncState == State::MOVE){
        useCurrentMode();
    }
}

void Controller::useCurrentMode(){
    if (s->currentMode == State::MANUAL) handleManual();
    else if (s->currentMode == State::AUTO) handleAutonomous();
    else if (s->currentMode == State::SCRIPT) handleScript();
}

void Controller::control() {
    listener->listen();

    // check of the initial connection with the pi
    if (s->connectionChanged) { s->changeConnection(); }

    // check for restart and adjust based on that
    if (s->restartChanged) { s->changeRestart() ; }
    // change the functional state of the pod if there is any change
    else if (s->functionalStateChanged){ s->changeFuncState(); }
    // change the mode if there is any change
    else if (s->modeChanged){ s->changeMode(); }


    useCurrentConnection();
}

void Controller::check() {
    //return;


    if (s->currentConnection == State::DISCONNECTED
            || s->currentFuncState == State::STOP)
        return;

    return;
    /*
    if (s->piCheck){
        heartBeatMiss = 0;
        s->piCheck = false;
    } else if (heartBeatMiss >= 2){
        *serial << encoder->encodeMessage("Check missed stopping the pod") << endl;
        s->stop = true;
    } else ++heartBeatMiss;
     */
}

void Controller::stop() {
    /*
     * Stop code here
     */
}

