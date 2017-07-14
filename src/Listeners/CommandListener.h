#ifndef CONTROL_COMMANDLISTENER_H
#define CONTROL_COMMANDLISTENER_H


#include <Arduino.h>
#include <ArduinoJson.h>
#include <Configurations/Config.h>
#include <Watchdog/State.h>

class CommandListener {
    State *s;

    // Fields for Serial Commands
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
    CommandListener(State *s);
    ~CommandListener();
    void listen();
};


#endif //CONTROL_COMMANDLISTENER_H
