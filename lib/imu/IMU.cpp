#include "IMU.h"
#include <Wire.h>

IMU::IMU() {
    imu.begin();
    imu.calibrate();
    imu.calibrateMag();
}


bool IMU::isStarted(){
    return imu.begin() != 0;
}


void IMU::setupGyro(uint8_t scale, uint8_t sampleRate, uint8_t flipX, uint8_t flipY, uint8_t flipZ) {
    imu.settings.gyro.scale = scale;
    imu.settings.gyro.sampleRate = sampleRate;
    imu.settings.gyro.flipX = flipX;
    imu.settings.gyro.flipY = flipY;
    imu.settings.gyro.flipZ = flipZ;
}


void IMU::setupAccel(uint8_t scale, uint8_t sampleRate) {
    imu.settings.accel.scale = scale;
    imu.settings.accel.sampleRate = sampleRate;
}


void IMU::setupMag(uint8_t scale, uint8_t sampleRate, uint8_t tempComp, uint8_t operatingMode) {
    imu.settings.mag.scale = scale;
    imu.settings.mag.sampleRate = sampleRate;
    imu.settings.mag.tempCompensationEnable = tempComp;
    imu.settings.mag.operatingMode = operatingMode;
}


float IMU::getX(imu_comp comp) {
    if(comp == GYRO){
        if (imu.gyroAvailable()){
            imu.gx = imu.readGyro(X_AXIS);
            return imu.calcGyro(imu.gx);
        } else
            return error_val;
    } else if (comp == ACCEL){
        if (imu.accelAvailable()){
            imu.ax = imu.readAccel(X_AXIS);
            return imu.calcAccel(imu.ax);
        } else
            return error_val;
    } else if (comp == MAG){
        if (imu.magAvailable()){
            imu.mx = imu.readMag(X_AXIS);
            return imu.calcMag(imu.mx);
        } else
            return error_val;
    }

    return error_val;
}


float IMU::getY(imu_comp comp) {
    if(comp == GYRO){
        if (imu.gyroAvailable()){
            imu.gy = imu.readGyro(Y_AXIS);
            return imu.calcGyro(imu.gy);
        } else
            return error_val;
    } else if (comp == ACCEL){
        if (imu.accelAvailable()){
            imu.ay = imu.readAccel(Y_AXIS);
            return imu.calcAccel(imu.ay);
        } else
            return error_val;
    } else if (comp == MAG){
        if (imu.magAvailable()){
            imu.my = imu.readMag(Y_AXIS);
            return imu.calcMag(imu.my);
        } else
            return error_val;
    }

    return error_val;
}


float IMU::getZ(imu_comp comp) {
    if(comp == GYRO){
        if (imu.gyroAvailable()){
            imu.gz = imu.readGyro(Z_AXIS);
            return imu.calcGyro(imu.gz);
        } else
            return error_val;
    } else if (comp == ACCEL){
        if (imu.accelAvailable()){
            imu.az = imu.readAccel(Z_AXIS);
            return imu.calcAccel(imu.az);
        } else
            return error_val;
    } else if (comp == MAG){
        if (imu.magAvailable()){
            imu.mz = imu.readMag(Z_AXIS);
            return imu.calcMag(imu.mz);
        } else
            return error_val;
    }

    return error_val;
}