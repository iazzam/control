#include "SensorPool.h"

using namespace wlp;

void SensorPool::read() {
    int size = sensors.size();

    for (int i = 0; i < size; ++i)
        sensors[i]->read();
}

void SensorPool::add(Sensor *t) {
    sensors.push_back(t);
}

Sensor &SensorPool::operator[](const uint8_t index) {
    return *sensors[index];
};

void SensorPool::destroy() {
    int size = sensors.size();

    for (int i = 0; i < size; ++i)
        delete sensors[i];

    delete this;
}

WSerial &operator <<(WSerial &serial, SensorPool &pool){
    int size = pool.sensors.size();

    for (int i = 0; i < size; ++i)
        serial << *pool.sensors[i];

    return serial;
}

