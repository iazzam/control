#include <Configurations/Config.h>
#include <Watchdog/State.h>
#include <Shared/JSONEncoder.h>
#include <WSerial.h>
#include "CommandListener.h"

CommandListener::CommandListener(State *s, const JSONEncoder *dh, WSerial *serial)
        : s{s}, dh{dh}, serial{serial} {
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
    *serial << dh->encodeCommand(command) << endl;

    const int BUFFER_SIZE = JSON_OBJECT_SIZE(2) + JSON_ARRAY_SIZE(1) + 40;
    StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(command);

    if (root.success() && root.containsKey(F("cmd")) && root.containsKey(F("val"))){
        String name = root[F("cmd")];
        uint8_t value = root[F("val")][0];

        if (name != SPEED && (value < 0 || value > 1)) return;

        if (name == EMERGENCY){
            *serial << dh->encodeMessage("Entering emergency mode") << endl;
            s->emergency = (bool)value;
        }
        else if (name == RESTARTS){
            *serial << dh->encodeMessage("Restart with state saved will be initiated") << endl;
            s->restartUnsaved = false;
            s->restartSaved = true;
        }
        else if (name == RESTARTUS){
            *serial << dh->encodeMessage("Restart with no state saved will be initiated") << endl;
            s->restartSaved = false;
            s->restartUnsaved = false;
        }
        else if (name == CONNECT){
            *serial << dh->encodeMessage("Pi is connected to Arduino") << endl;
            s->connect = (bool)value;
        }
        else if (name == PICHECK)       s->piCheck = true;
        else if (name == AUTONOMOUS){
            *serial << dh->encodeMessage("Autonomous mode selected") << endl;
            s->autonomous = (bool)value;
            s->manual = false;
            s->script = false;
        } else if (name == MANUAL){
            *serial << dh->encodeMessage("Manual mode selected") << endl;
            s->manual = (bool)value;
            s->script = false;
            s->autonomous = false;
        } else if (name == SCRIPT) {
            *serial << dh->encodeMessage("Script mode selected") << endl;
            s->script = (bool) value;
            s->manual = false;
            s->autonomous = false;
        } else if (name == BRAKE){
            *serial << dh->encodeMessage("Braking will be initiated") << endl;
            s->brake = (bool)value;
        }
        else if (name == STOP){
            *serial << dh->encodeMessage("Pod Stop will be initiated") << endl;
            s->stopped = (bool)value;
        }
        else if (name == SPEED){
            *serial << dh->encodeMessage("Pod speed will be changed to " + value) << endl;
            s->speed = value;
        }
        else if (name == BALLValve){
            if (value)
                *serial << dh->encodeMessage("Ball Valve state will be changed to on") << endl;
            else
                *serial << dh->encodeMessage("Ball Valve state will be changed to off") << endl;
            s->ballValve = (bool)value;
        }
        else if (name == DPR){
            if (value)
                *serial << dh->encodeMessage("DPR state will be changed to on") << endl;
            else
                *serial << dh->encodeMessage("DPR state will be changed to off") << endl;
            s->dpr = (bool)value;
        }
    }
}


