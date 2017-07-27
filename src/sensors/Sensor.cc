#include <USBAPI.h>
#include <JsonHandler.h>
#include "Sensor.h"

using namespace wlp;

Sensor::Sensor(const String name, const int rate, const int numInputs, const bool heartBeat)
        : name{name}, rate{rate}, numInputs{numInputs}, heartBeat{heartBeat}{
    check = 0;
    array = new float[numInputs];
    JSONString = "";
    arrayCounter = 0;
    printCounter = 0;
    prevTime = millis();
}

Sensor::~Sensor() {
    delete [] array;
}

bool Sensor::rateCheck() {
    if (millis() - prevTime >= 1000){
        printCounter = 0;
        prevTime = millis();
    }

    if (printCounter < rate){
        ++printCounter;
        return true;
    }

    return false;
}

String &Sensor::getJSON(const int check) {
    if (check < 0)
        JSONString = wlp::json.encodeSensor(name, array, numInputs);
    else
        JSONString = wlp::json.encodeSensor(name, array, numInputs, check);

    return JSONString;
}

void Sensor::add(const float val) {
    if (arrayCounter >= numInputs)
        arrayCounter = 0;

    array[arrayCounter] = val;
    ++arrayCounter;
}

float Sensor::get(const int index){
    if (index < 0 || index >= numInputs)
        return -1;

    return array[index];
}

String &Sensor::getName() { return name; }

const int Sensor::getRate() { return rate; }

void Sensor::setCheck(const int check) { this->check = check; }

WSerial &operator <<(WSerial &serial, Sensor &sensor){
    if (!sensor.rateCheck()) return serial;

    if (sensor.heartBeat)
        serial << sensor.getJSON(sensor.check) << endl;
    else
        serial << sensor.getJSON() << endl;

    return serial;
}
