
#include "SensorPool.h"

void SensorPool::read() {
    for (auto p : sensors)
        p->read();
}


void SensorPool::add(Sensor *s) {
    sensors.push_back(s);
}

Sensor &SensorPool::operator[](const uint8_t index) {
    return *sensors[index];
};


void SensorPool::destroy() {
    for (auto p : sensors)
        delete p;

    delete this;
}

WSerial &operator <<(WSerial &serial, SensorPool &pool){
    for (auto p : pool.sensors)
        serial << *p;

    return serial;
}

