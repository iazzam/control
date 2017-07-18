/*!
 * @author Deep Dhillon
 * @date July 11, 2017
 * @brief Library to access and print magnetometer data gathered from IMU
 */

#ifndef SENSORS_MAG_H
#define SENSORS_MAG_H


#include <Sensor.h>
#include "SparkfunIMU.h"

class Mag : public Sensor {
    SparkfunIMU &imu;

    enum Coordinates{
        X = 0,
        Y = 1,
        Z = 2
    };

    int counter = 0;
    const static float DECLINATION = -8.58; // Declination (degrees) in Boulder, CO.

    LSM9DS1 &getInstance();

public:
    Mag(const String name, const uint8_t freq, SparkfunIMU &imu);

    /*!
     * reads magnetometer and makes it ready for data collection
     * @return 1 for success of the read and 0 for the fail
     */
    float read();

    /*!
     * data for the x coordinate of the magnetometer
     * @return value for x axis of gyro
     */
    float getX();

    /*!
     * data for the y coordinate of the magnetometer
     * @return value for y axis of gyro
     */
    float getY();

    /*!
     * data for the z coordinate of the magnetometer
     * @return value for z axis of gyro
     */
    float getZ();

    /*!
     * heading of the magnetic field calculated using mag data
     * @param mx is the x axis value of mag
     * @param my is the y axis value of mag
     * @param declination is the earth's magnetic field
     * @return
     */
    float getHeading(const float &mx, const float &my, const float &declination=DECLINATION);

    /*!
     * specifies the range setting for the magnetometer
     * @param scale is the full-scale range of magnetometer. It can be set to either 4, 18, 12, or 16
     */
    void setScale(const uint16_t scale);

    /*!
     * specifies the sample rate setting for the magnetometer
     * @param sampleRate is the output data rate of gyro. It can be set between 0 and 7
     */
    void setSampleRate(const uint8_t rate);

    /*!
     * make magnetometer independent or dependent on temperature
     * @param val is used to turn temp compensation on and off
     */
    void setTempCompensation(const bool val);

    /*!
     * sets the x, y and z performance to either 0, 1, 2 or 3
     * @param mode is the mode being set
     */
    void setMagPerformance(const uint8_t mode);

    /*!
     * sets the operating mode of the magnetometer. operatingMode can be 0-2
     * @param mode is the mode being set
     */
    void setOperatingMode(const uint8_t mode);
};


#endif //SENSORS_MAG_H
