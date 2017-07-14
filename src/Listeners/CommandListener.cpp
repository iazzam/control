#include "CommandListener.h"

CommandListener::CommandListener(State *s) : s{s} {
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
        uint8_t value = root[F("val")][0];

        if (name == EMERGENCY){
            if (value < 0 || value > 1) return;
            s->emergency = (bool)value;
        } else if (name == RESTART){
            s->restart = (bool)value;
        } else if (name == PICHECK){
            s->piCheck = (bool)value;
        } else if (name == AUTONOMOUS){
            if (value < 0 || value > 1) return;
            s->autonomous = (bool)value;
            s->manual = false;
            s->script = false;
        } else if (name == MANUAL){
            if (value < 0 || value > 1) return;
            s->manual = (bool)value;
            s->script = false;
            s->autonomous = false;
        } else if (name == SCRIPT){
            if (value < 0 || value > 1) return;
            s->script = (bool)value;
            s->manual = false;
            s->autonomous = false;
        } else if (name == BRAKE){
            if (value < 0 && value > 1) return;
            s->brake = (bool)value;
        } else if (name == STOP) {
            if (value < 0 && value > 1) return;
            s->stopped = (bool) value;
        } else if (name == SPEED){
            if (value < 0 && value > 100) return;
            s->speed = value;
        } else if (name == BALLValve){
            if (value < 0 || value > 1) return;
            s->ballValve = (bool)value;
        } else if (name == DPR){
            if (value < 0 || value > 1) return;
            s->dpr = (bool)value;
        }
    }
}


