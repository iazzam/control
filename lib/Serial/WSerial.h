#ifndef CONTROL_WSERIAL_H
#define CONTROL_WSERIAL_H

#include <HardwareSerial.h>
#include <WString.h>

static const String &endl = "\n";

class WSerial{
    size_t readBytes(char *buffer, size_t length);
    size_t readBytesUntil(char terminator, char *buffer, size_t length);
    String readString();
    String readStringUntil(char terminator);

    friend WSerial &operator<<(WSerial& serial, const String &val);
    friend WSerial &operator<<(WSerial& serial, const int &val);
    friend WSerial &operator<<(WSerial& serial, const double &val);
    friend WSerial &operator<<(WSerial& serial, const float &val);
};

WSerial &operator<<(WSerial& serial, const String &val);
WSerial &operator<<(WSerial& serial, const int &val);
WSerial &operator<<(WSerial& serial, const double &val);
WSerial &operator<<(WSerial& serial, const float &val);



#endif //CONTROL_WSERIAL_H
