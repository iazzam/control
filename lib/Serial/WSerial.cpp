#include "WSerial.h"

WSerial &operator<<(WSerial &serial, const String &val) {
    Serial.print(val);
    return serial;
}

WSerial &operator<<(WSerial &serial, const int &val) {
    Serial.print(val);
    return serial;
}

WSerial &operator<<(WSerial &serial, const double &val) {
    Serial.print(val);
    return serial;
}

WSerial &operator<<(WSerial &serial, const float &val) {
    Serial.print(val);
    return serial;
}

size_t WSerial::readBytes(char *buffer, size_t length) {
    return Serial.readBytes(buffer, length);
}

size_t WSerial::readBytesUntil(char terminator, char *buffer, size_t length) {
    return Serial.readBytesUntil(terminator, buffer, length);
}

String WSerial::readString() {
    return Serial.readString();
}

String WSerial::readStringUntil(char terminator) {
    return Serial.readStringUntil(terminator);
}
