#include "Gyro.h"

Gyro::Gyro(const String name, const uint8_t freq, SparkfunIMU &imu)
        : Sensor{name, 60, 4, true}, imu{imu} {}

float Gyro::read() {
    if (!rateCheck()) return 0;

    ++counter;

    int status = 0;

    if (getInstance().gyroAvailable()) {
        getInstance().readGyro();
        status = 1;
    }

    add(getInstance().calcGyro(getInstance().gx));
    add(getInstance().calcGyro(getInstance().gy));
    add(getInstance().calcGyro(getInstance().gz));
    add(status);
    setCheck(counter);

    return status;
}

float Gyro::getX() {
    return get(X);
}

float Gyro::getY() {
    return get(Y);
}

float Gyro::getZ() {
    return get(Z);
}

void Gyro::setScale(const uint16_t scale) {
    if (scale == 245 || scale == 500 || scale == 2000)
        getInstance().settings.gyro.scale = scale;
}

void Gyro::setSampleRate(const uint8_t rate) {
    if (rate >= 1 && rate <= 6)
        getInstance().settings.gyro.sampleRate = rate;
}

void Gyro::flipX() {
    getInstance().settings.gyro.flipX = (uint8_t) true;
}

void Gyro::flipY() {
    getInstance().settings.gyro.flipY = (uint8_t) true;
}

void Gyro::flipZ() {
    getInstance().settings.gyro.flipZ = (uint8_t) true;
}

void Gyro::setHPF(const bool val) {
    getInstance().settings.gyro.HPFEnable = (uint8_t) val;
}

LSM9DS1 &Gyro::getInstance() {
    return imu.getImu();
}
