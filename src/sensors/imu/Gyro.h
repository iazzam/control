/*!
 * @author Deep Dhillon
 * @date July 11, 2017
 * @brief Library to access and print gyroscope data gathered from IMU
 */

#ifndef SENSORS_GYRO_H
#define SENSORS_GYRO_H


#include <sensors/Sensor.h>
#include "SparkfunIMU.h"

class Gyro : public Sensor {
    SparkfunIMU &imu;

    enum Coordinates{
        X = 0,
        Y = 1,
        Z = 2
    };

    int counter = 0;

    LSM9DS1 &getInstance();

public:
    /*!
     * Single constructor creates creates Gyroscope IMU sensor
     * @param name sensor name
     * @param freq frequency of the output
     * @param imu IMU unit this sensor belongs to
     */
    Gyro(const String name, const uint8_t freq, SparkfunIMU &imu);

    /*!
     * Reads Gyroscope and makes it ready for data collection
     * @return 1 for success of the read and 0 for the fail
     */
    float read();

    /*!
     * Data for the x coordinate of the gyroscope
     * @return value for x axis of gyro
     */
    float getX();

    /*!
     * Data for the y coordinate of the gyroscope
     * @return value for y axis of gyro
     */
    float getY();

    /*!
     * Data for the z coordinate of the gyroscope
     * @return value for z axis of gyro
     */
    float getZ();

    /*!
     * Specifies the range setting for the gyroscope
     * @param scale is the full-scale range of gyroscope. It can be set to either 245, 500, or 2000
     */
    void setScale(const uint16_t scale);

    /*!
     * Specifies the sample rate setting for the gyroscope
     * @param sampleRate is the output data rate of gyro. It can be set between 1 and 6
     */
    void setSampleRate(const uint8_t rate);

    /*!
     * Sets high-pass filter on and off
     * @param val is used to turn high-pass filter on and off
     */
    void setHPF(const bool val);

    /*!
     * Switches the positive/negative orientation of x axis
     */
    void flipX();

    /*!
     * Switches the positive/negative orientation of y axis
     */
    void flipY();

    /*!
     * Switches the positive/negative orientation of z axis
     */
    void flipZ();
};


#endif //SENSORS_GYRO_H
