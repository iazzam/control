/*!
 * @author Deep Dhillon
 * @date July 11, 2017
 * @brief Library to access and print accelerometer data gathered from IMU
 */

#ifndef SENSORS_ACCEL_H
#define SENSORS_ACCEL_H

#include <sensors/Sensor.h>
#include "SparkfunIMU.h"

class Accel : public Sensor{
    SparkfunIMU &imu;

    enum Coordinates{
        X = 0,
        Y = 1,
        Z = 2
    };

    LSM9DS1 &getInstance();

public:
    /*!
     * Single constructor creates creates Accelerometer IMU sensor
     * @param name sensor name
     * @param freq frequency of the output
     * @param imu IMU unit this sensor belongs to
     */
    Accel(const String name, const uint8_t freq, SparkfunIMU &imu);

    /*!
     * Reads accelerometer and makes it ready for data collection
     * @return 1 for success of the read and 0 for the fail
     */
    float read();

    /*!
     * Data for the x coordinate of the accelerometer
     * @return value for x axis of accelerometer
     */
    float getX();

    /*!
     * Data for the y coordinate of the accelerometer
     * @return value for y axis of accelerometer
     */
    float getY();

    /*!
     * Data for the z coordinate of the accelerometer
     * @return value for z axis of accelerometer
     */
    float getZ();

    /*!
     * Calculates the roll based on acceleration data
     * @param ay is the value for y axis of accelerometer
     * @param az is the value for z axis of accelerometer
     * @return the calculated roll
     */
    float getRoll(const float &ay, const float &az) const;

    /*!
     * Calculates the pitch based on acceleration data
     * @param ax is the value for x axis of accelerometer
     * @param az is the value for y axis of accelerometer
     * @param az is the value for z axis of accelerometer
     * @return the calculated pitch
     */
    float getPitch(const float &ax, const float &ay, const float &az) const;

    /*!
     * Specifies the range setting for the accelerometer
     * @param scale is the full-scale range of accelerometer. It can be set to either 2, 4, 8 or 16
     */
    void setScale(const uint16_t scale);

    /*!
     * Specifies the sample rate setting for the accelerometer
     * @param sampleRate is the output data range of accelerometer. It can be set between 1 and 6
     */
    void setSampleRate(const uint8_t rate);

    /*!
     * Sets high resolution on and off
     * @param val is used to turn high resolution on and off
     */
    void setHighRes(const bool val);

    /*!
     * Sets the bandwidth for high resolution
     * @param band sets the bandwidth based on it
     */
    void setHighResBand(const uint8_t band);
};


#endif //SENSORS_ACCEL_H
