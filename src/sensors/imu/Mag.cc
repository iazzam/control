#include "Mag.h"

Mag::Mag(const String name, const uint8_t freq, SparkfunIMU &imu)
        : Sensor{name, freq, 5}, imu{imu} {}

float Mag::read() {
    if (!rateCheck()) return 0;

    int status = 0;

    if (getInstance().magAvailable()) {
        getInstance().readMag();
        status = 1;
    }

    add(getInstance().calcMag(getInstance().mx));
    add(getInstance().calcMag(getInstance().my));
    add(getInstance().calcMag(getInstance().mz));
    add(getHeading(getX(), getY()));
    add(status);

    return status;
}

float Mag::getX() {
    return get(X);
}

float Mag::getY() {
    return get(Y);
}

float Mag::getZ() {
    return get(Z);
}

void Mag::setScale(const uint16_t scale) {
    if (scale == 4 || scale == 8 || scale == 12 || scale == 16)
        getInstance().settings.mag.scale = scale;
}

void Mag::setSampleRate(const uint8_t rate) {
    if (rate >= 0 && rate <= 7)
        getInstance().settings.mag.sampleRate = rate;
}

float Mag::getHeading(const float &mx, const float &my, const float &declination) {
    float heading;
    if (my == 0)
        heading = (mx < 0) ? PI : 0;
    else
        heading = atan2(mx, my);

    heading -= declination * PI / 180;

    if (heading > PI) heading -= (2 * PI);
    else if (heading < -PI) heading += (2 * PI);
    else if (heading < 0) heading += 2 * PI;

    heading *= 180.0 / PI;

    return heading;
}

void Mag::setTempCompensation(const bool val) {
    getInstance().settings.mag.tempCompensationEnable = (uint8_t)val;
}

void Mag::setMagPerformance(const uint8_t mode) {
    if (mode >= 0 && mode <= 3){
        getInstance().settings.mag.XYPerformance = mode;
        getInstance().settings.mag.ZPerformance = mode;
    }
}

void Mag::setOperatingMode(const uint8_t mode) {
    if (mode >= 0 && mode <= 2)
        getInstance().settings.mag.operatingMode = mode;
}

LSM9DS1 &Mag::getInstance() {
    return imu.getImu();
}
