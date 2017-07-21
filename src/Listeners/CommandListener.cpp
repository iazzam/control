#include <Watchdog/State.h>
#include "CommandListener.h"
#include <Configurations/Config.h>

CommandListener::CommandListener(State *s, const JSONEncoder *dh, WSerial *serial, Config *config)
        : s{s}, dh{dh}, serial{serial}, config{config}{
    receivedChars = new char[maxChar];
}

CommandListener::~CommandListener() {
    delete [] receivedChars;
}

void CommandListener::listen() {
    // read command if available
    readCommand();

    // parse the command and set flags
    if (newData){
        parseCommand(receivedChars);
        newData = false;
    }
}

void CommandListener::readCommand() {
    char curr_char;

    while (Serial.available() > 0 && !newData) {
        curr_char = (char)Serial.read();

        if (reading) {
            if (curr_char != endMarker) {
                receivedChars[charIndex] = curr_char;
                ++charIndex;

                // in case of overflow
                if (charIndex >= maxChar)
                    charIndex = maxChar - 1;
            } else {
                receivedChars[charIndex] = curr_char;
                ++charIndex;
                receivedChars[charIndex] = '\0'; // terminate the string
                reading = false;
                charIndex = 0;
                newData = true;
            }
        } else if (curr_char == startMarker) {
            receivedChars[charIndex] = curr_char;
            ++charIndex;
            reading = true;
        }
    }
}

void CommandListener::parseCommand(const String &command) {
    const int BUFFER_SIZE = JSON_OBJECT_SIZE(2) + JSON_ARRAY_SIZE(1) + 40;
    StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(command);

    if (root.success() && root.containsKey(F("cmd")) && root.containsKey(F("val"))){
        String name = root[F("cmd")];
        int value = root[F("val")][0];

        // no matter what always listen for connection
        if (name == config->CONNECT){
            s->connectionChanged = true;
            s->connect = (bool)value;
        }


        if (s->currentConnection == s->DISCONNECTED) return;


        if ((name != config->SPEED_MAG  && name != config->SPEED_DRIVE) &&
                (value < 0 || value > 1)) return;

        if (name != "check")
            *serial << dh->encodeCommand(command) << endl;

        if (name == config->EMERGENCY){
            s->functionalStateChanged = true;
            s->emergency = (bool)value;
        }
        else if (name == config->RESTARTS){
            s->restartChanged = true;
            s->restartUnsaved = false;
            s->restartSaved = true;
        }
        else if (name == config->RESTARTUS){
            s->restartChanged = true;
            s->restartSaved = false;
            s->restartUnsaved = true;
        }
        else if (name == config->PICHECK){
            s->piCheck = true;
        }
        else if (name == config->AUTONOMOUS){
            s->modeChanged = true;
            s->autonomous = true;
            s->manual = false;
            s->script = false;
        } else if (name == config->MANUAL){
            s->modeChanged = true;
            s->manual = true;
            s->script = false;
            s->autonomous = false;
        } else if (name == config->SCRIPT) {
            s->modeChanged = true;
            s->script = true;
            s->manual = false;
            s->autonomous = false;
        } else if (name == config->BRAKE){
            s->brake = (bool)value;
        }
        else if (name == config->STOP){
            s->functionalStateChanged = true;
            s->stop = (bool)value;
            s->move = !s->stop;
        }
        else if (name == config->SPEED_MAG){
            s->speedMag = value;
            *serial << s->speedMag << endl;
            s->magSpeedChanged = true;
        } else if (name == config->SPEED_DRIVE){
            s->speedDrive = value;
            *serial << s->speedDrive << endl;
            s->driveSpeedChanged = true;
        }
        else if (name == config->BALLValve){
            if (value)
                *serial << dh->encodeMessage("Ball Valve state changed to on") << endl;
            else
                *serial << dh->encodeMessage("Ball Valve state will be changed to off") << endl;
            s->ballValve = (bool)value;
        }
        else if (name == config->DPR){
            if (value)
                *serial << dh->encodeMessage("DPR state will be changed to on") << endl;
            else
                *serial << dh->encodeMessage("DPR state will be changed to off") << endl;
            s->dpr = (bool)value;
        } else if (name == config->EMERGENCY_DRIVE){
            s->emergencyDrive = (bool)value;
            s->eDriveChanged = true;
        } else if (name == config->EMERGENCY_DROP){
            s->emergencyDrop = (bool)value;
            s->eDropChanged = true;
        }
    }
}


