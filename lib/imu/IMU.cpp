#include "IMU.h"
#include <Wire.h>

#define LSM9DS1_M	0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG	0x6B // Would be 0x6A if SDO_AG is LOW

#define DECLINATION -8.58 // Declination (degrees) in Boulder, CO.

void IMU::setup(){
    imu.settings.device.commInterface = IMU_MODE_I2C;
    imu.settings.device.mAddress = LSM9DS1_M;
    imu.settings.device.agAddress = LSM9DS1_AG;
}

void IMU::calibrate(){
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

float IMU::getRoll(){
    float ay = getY(ACCEL);
    float az = getZ(ACCEL);

    float roll = atan2(ay, az);
    roll  *= 180.0 / PI;
    return roll;
}

float IMU::getPitch(){
    float ax = getX(ACCEL);
    float ay = getY(ACCEL);
    float az = getZ(ACCEL);

    float pitch = atan2(-ax, sqrt(ay * ay + az * az));
    pitch *= 180.0 / PI;
    return pitch;
}

float IMU::getHeading(){
    float mx = getX(MAG);
    float my = getY(MAG);

    float heading;
    if (my == 0)
        heading = (mx < 0) ? PI : 0;
    else
        heading = atan2(mx, my);

    heading -= DECLINATION * PI / 180;

    if (heading > PI) heading -= (2 * PI);
    else if (heading < -PI) heading += (2 * PI);
    else if (heading < 0) heading += 2 * PI;

    heading *= 180.0 / PI;

    return heading;
}

void IMU::serialPrint(imu_comp comp, WSerial &serial){
    float *data = new float[6];
    data[0] = getX(comp);
    data[1] = getY(comp);
    data[2] = getZ(comp);
    data[3] = getRoll();
    data[4] = getPitch();
    data[5] = getHeading();

    if (data[0] <= -1000 || data[1] <= -1000 || data[2] <= -1000){
        delete [] data;
        return;
    }

    String name = "";
    int check = -1;

    if (comp == GYRO){
        name = "gyro";
        check = counter;
        ++counter;

        serial << dh.getJSONString(name, data, 6, check) << endl;

        delete [] data;

        return;
    }
    else if (comp == ACCEL)
        name = "accel";
    else if (comp == MAG)
        name = "mag";

    serial << dh.getJSONString(name, data, 6) << endl;

    delete [] data;
}