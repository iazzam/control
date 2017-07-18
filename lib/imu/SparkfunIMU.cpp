//
// Created by Deep6 on 2017-07-11.
//

#include "SparkfunIMU.h"

SparkfunIMU::SparkfunIMU() {
    imu.settings.device.commInterface = IMU_MODE_I2C;
    imu.settings.device.mAddress = LSM9DS1_M;
    imu.settings.device.agAddress = LSM9DS1_AG;
}

uint16_t SparkfunIMU::begin() {
    uint16_t status = imu.begin();

    if (status){
        imu.calibrate();
        imu.calibrateMag();
    }

    return status;
}

LSM9DS1 &SparkfunIMU::getImu() {
    return imu;
}
