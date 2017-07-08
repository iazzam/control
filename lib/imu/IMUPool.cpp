#include "IMUPool.h"

IMUPool::IMUPool(unsigned int num_sensors) : sensor_total{num_sensors},
                                             sensors{new IMU*[sensor_total]}{

    for (unsigned int i = 0; i < sensor_total; i++)
        sensors[i] = new IMU;
}


IMUPool::~IMUPool() {
    for (unsigned int i = 0; i < sensor_total; i++)
        delete sensors[i];

    delete [] sensors;
}


bool IMUPool::sensorsWorking() {
    for (unsigned int i = 0; i < sensor_total; i++)
        if (!sensors[i]->isStarted())
            return false;

    return true;
}


void IMUPool::serialPrint(unsigned int sensor, imu_comp comp) {
    float *comp_data = new float[4];

    comp_data[0] = sensor;
    comp_data[1] = getX(sensor, comp);
    comp_data[2] = getY(sensor, comp);
    comp_data[3] = getZ(sensor, comp);

    String sensor_name = "";

    if (comp == GYRO) sensor_name = "gyro";
    else if (comp == ACCEL) sensor_name = "accelerometer";
    else if (comp == MAG) sensor_name = "magnetometer";

    Serial.println(data_handler.getJSONString(sensor_name, comp_data, 4));

    delete [] comp_data;
}


int IMUPool::getTotal() {
    return sensor_total;
}


float IMUPool::getX(unsigned int sensor, imu_comp comp) {
    return sensors[sensor]->getX(comp);
}


float IMUPool::getY(unsigned int sensor, imu_comp comp) {
    return sensors[sensor]->getY(comp);
}


float IMUPool::getZ(unsigned int sensor, imu_comp comp) {
    return sensors[sensor]->getZ(comp);
}