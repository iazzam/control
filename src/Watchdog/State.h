#ifndef CONTROL_STATE_H
#define CONTROL_STATE_H

#include <WSerial.h>
#include <Shared/JSONEncoder.h>
#include <Listeners/CommandListener.h>

class State {
private:
    // essentials for the State
    WSerial *serial;
    JSONEncoder *encoder;

    // mode of the pod
    bool autonomous = false;
    bool manual = true;
    bool script = false;

    // functional state of the pod
    bool emergency = false;
    bool stop = false;
    bool move = true;

    // restart procedures of the pod
    bool restartSaved = false;
    bool restartUnsaved = false;

    // connection of the pod with pi
    bool connect = true;

public:
    enum Mode{
      MANUAL,
      AUTO,
      SCRIPT
    };

    enum FuncState{
      EMERGENCY,
      STOP,
      MOVE
    };

    enum Restart{
      RESTARTS,
      RESTARTUS,
      NONE
    };

    enum Connection{
      CONNECTED,
      DISCONNECTED
    };

    void setEssentials(WSerial *serial, JSONEncoder *encoder){
        this->serial = serial;
        this->encoder = encoder;
    }

    // method and variables to change the mode being used
    bool modeChanged = false;
    Mode currentMode = MANUAL;

    void changeMode() {
        if (currentConnection == DISCONNECTED) return;

        String message = "current mode changed to ";

        if (manual){
            currentMode = MANUAL;
            message += "manual";
        } else if (autonomous){
            currentMode = AUTO;
            message += "autonomous";
        } else if (script){
            currentMode = SCRIPT;
            message += "script";
        }

        *serial << encoder->encodeMessage(message) << endl;

        modeChanged = false;
    }

    // method and variables to change the functional state of the pod
    bool functionalStateChanged = false;
    FuncState currentFuncState = MOVE;

    void changeFuncState(){
        if (currentConnection == DISCONNECTED) return;

        String message = "current Functional State changed to ";

        if (emergency) {
            currentFuncState = EMERGENCY;
            message += "emergency";
        } else if (stop) {
            currentFuncState = STOP;
            message += "stop";
        } else if (move) {
            currentFuncState = MOVE;
            message += "move";
        }

        *serial << encoder->encodeMessage(message) << endl;

        functionalStateChanged = false;
    }

    // methods and variables to change the restart state of the pod
    bool restartChanged = false;
    Restart currentRestart = NONE;

    void changeRestart(){
        if (currentConnection == DISCONNECTED) return;

        String message = "current restart changed to ";

        if (restartSaved) {
            currentRestart = RESTARTS;
            message += "restart saved";
        } else if (restartUnsaved) {
            currentRestart = RESTARTUS;
            message += "restart unsaved";
        } else{
            currentRestart = NONE;
            message += "no restart";
        }

        *serial << message << endl;

        restartChanged = false;
    }

    void turnRestartOff(){
        restartSaved = false;
        restartUnsaved = false;
        currentRestart = NONE;
    }

    // method and variables to change the connection of the pod
    bool connectionChanged = false;
    Connection currentConnection = DISCONNECTED;

    void changeConnection(){
        String message = "current connection changed to ";

        if (connect) {
            currentConnection = CONNECTED;
            message += "connected";
        } else {
            currentConnection = DISCONNECTED;
            message += "disconnected";
        }

        *serial << encoder->encodeMessage(message) << endl;

        connectionChanged = false;
    }



    uint8_t speedMag = 0;
    int speedDrive = 0;
    bool magSpeedChanged = false;
    bool driveSpeedChanged = false;


    // connection with pi
    
    // on off states for overall pod functioning

    bool reset = false;


    bool speedIncreasing = false;
    bool eDropChanged = false;
    bool eDriveChanged = false;

    // on off components' states
    bool ballValve = 0;
    bool dpr = 0;
    bool brake;
    bool emergencyDrive = false;
    bool emergencyDrop = false;

    // variable components' states
    uint8_t speed = 0;


    // essentials for this state



    bool piCheck = false;


    friend class CommandListener;
};


#endif //CONTROL_STATE_H
