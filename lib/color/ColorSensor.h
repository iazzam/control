#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <DataHandler.h>

class ColorSensor{
    DataHandler data_handler;

    const uint8_t out1APin = 0;
    const uint8_t out2APin = 1;
    const uint8_t out3APin = 2;

public:
    uint8_t getLimitOut1();
    uint8_t getLimitOut2();
    uint8_t getLimitOut3();
    void serialPrint();
    uint8_t getColorRange();
};

#endif
