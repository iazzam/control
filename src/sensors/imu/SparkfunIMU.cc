#include "SparkfunIMU.h"

SparkfunIMU::SparkfunIMU(uint8_t adrM, uint8_t adrAG) 
        : LSM9DS1_M{adrM}, LSM9DS1_AG{adrAG} {
    imu.settings.device.commInterface = IMU_MODE_I2C;
    imu.settings.device.mAddress = LSM9DS1_M;
    imu.settings.device.agAddress = LSM9DS1_AG;
}

bool SparkfunIMU::begin() {
    bool status = (bool)imu.begin();

    if (status){
        imu.calibrate();
        imu.calibrateMag();
    }

    return status;
}

LSM9DS1 &SparkfunIMU::getImu() {
    return imu;
}
