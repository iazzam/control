//
// Created by Deep6 on 2017-06-28.
//

#ifndef SENSORS_IRTEMP_H
#define SENSORS_IRTEMP_H

#include <Sensor.h>
#include <Adafruit_TMP006.h>

class IRTemp : public Sensor{
private:
    Adafruit_TMP006 tmp006{0x40};
public:
    IRTemp(const String &name, const uint8_t freq);

    float read();
};


#endif //SENSORS_IRTEMP_H
