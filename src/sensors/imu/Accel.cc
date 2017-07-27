#include "Accel.h"

Accel::Accel(const String name, const uint8_t freq, SparkfunIMU &imu)
        : Sensor(name, freq, 6), imu{imu} {}

float Accel::read() {
    if (!rateCheck()) return 0;

    int status = 0;

    if (getInstance().accelAvailable()) {
        getInstance().readAccel();
        status = 1;
    }

    add(getInstance().calcAccel(getInstance().ax));
    add(getInstance().calcAccel(getInstance().ay));
    add(getInstance().calcAccel(getInstance().az));
    add(getRoll(getY(), getZ()));
    add(getPitch(getX(), getY(), getZ()));
    add(status);

    return status;
}

float Accel::getX() {
    return get(X);
}

float Accel::getY() {
    return get(Y);
}

float Accel::getZ() {
    return get(Z);
}

float Accel::getRoll(const float &ay, const float &az) const {
    float roll = atan2(ay, az);
    roll  *= 180.0 / PI;
    return roll;
}

float Accel::getPitch(const float &ax, const float &ay, const float &az) const {
    float pitch = atan2(-ax, sqrt(ay * ay + az * az));
    pitch *= 180.0 / PI;
    return pitch;
}

void Accel::setScale(const uint16_t scale) {
    if (scale == 2 || scale == 4 || scale == 8 || scale == 16)
        getInstance().settings.accel.scale = scale;
}

void Accel::setSampleRate(const uint8_t rate) {
    if (rate >= 1 && rate <= 6)
        getInstance().settings.accel.sampleRate = rate;
}

void Accel::setHighRes(const bool val) {
    getInstance().settings.accel.sampleRate = (uint8_t) val;
}

void Accel::setHighResBand(const uint8_t band) {
    if (band >= 0 && band <= 3)
        getInstance().settings.accel.highResBandwidth = band;
}

LSM9DS1 &Accel::getInstance() {
    return imu.getImu();
}
