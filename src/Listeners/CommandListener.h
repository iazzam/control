#ifndef CONTROL_COMMANDLISTENER_H
#define CONTROL_COMMANDLISTENER_H


#include <Arduino.h>
#include <JSONEncoder.h>
#include <StandardCplusplus.h>

class JSONEncoder;
class WSerial;
class State;
class String;

class CommandListener {
    State *s;
    const JSONEncoder *dh;
    WSerial *serial;


    // Fields for Serial Commands reading
    const uint8_t maxChar = 30;       /*!< Maximum length of commands allowed */
    char *receivedChars;
    bool newData = false;
    bool reading = false;
    uint8_t charIndex = 0;
    char startMarker = '{';           /*!< Will only read commands that start with { */
    char endMarker = '}';             /*!< Will only read commands that end with } */


    void readCommand();
    void parseCommand(const String &command);
public:
    CommandListener(State *s, const JSONEncoder *dh, WSerial *serial);
    ~CommandListener();
    void listen();
};


#endif //CONTROL_COMMANDLISTENER_H
