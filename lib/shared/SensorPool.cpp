
#include "SensorPool.h"

void SensorPool::read() {
    for (auto p : sensors)
        p->read();
}

void SensorPool::add(Sensor *s) {
    sensors.push_back(s);
}

Sensor &SensorPool::get(const String name) {
    for (auto p : sensors)
        if (p->getName() == name)
            return *p;

    return *sensors.at(0);
}

Sensor &SensorPool::get(const int index) {
    return *sensors.at(0);
}

int SensorPool::find(const String name) {
    int size = sensors.size();

    for (unsigned i = 0; i < size; ++i)
        if (sensors.at(i)->getName() == name)
            return i;

    return -1;
}

void SensorPool::destroy() {
    for (auto p : sensors)
        delete p;

    delete this;
}

WSerial &operator <<(WSerial &serial, SensorPool &pool){
    for (auto p : pool.sensors)
        serial << *p;

    return serial;
};



