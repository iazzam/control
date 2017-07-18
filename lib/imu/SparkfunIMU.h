#ifndef SENSORS_SPARKFUNIMU_H
#define SENSORS_SPARKFUNIMU_H

#include <Arduino.h>
#include <SparkFunLSM9DS1.h>

class SparkfunIMU {
    uint8_t LSM9DS1_M = 0x1E;
    uint8_t LSM9DS1_AG = 0x6B;

    LSM9DS1 imu;

public:
    SparkfunIMU();
    uint16_t begin();
    LSM9DS1 &getImu();
};


#endif //SENSORS_SPARKFUNIMU_H
