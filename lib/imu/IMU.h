/*!
 * @author Deep Dhillon
 * @date 2017-06-27
 * @brief This class handles accelerometer, gyroscope and magnetometer and provides an interface
 * to access the data and manage the sensors
 */


#ifndef NEW_SENSORS_IMU_H
#define NEW_SENSORS_IMU_H


#include <SparkFunLSM9DS1.h>


/*!
 * @enum imu_comp
 * enum constants allow for the client to specify IMU component
 */
/*!
 * @var imu_comp:GYRO
 * Should be used to access data for gyroscope
 */
/*!
 * @var imu_comp:ACCEL
 * Should be used to access data for accelerometer
 */
/*!
 * @var imu_comp:MAG
 * Should be used to access data for magnetometer
 */
enum imu_comp {
    GYRO = 0,
    ACCEL = 1,
    MAG = 2
};

class IMU {
    LSM9DS1 imu;
    const float error_val = -99999.00000; /*!<when a sensor does not have a value, this error value is given */
public:
    /*!
     * Single no param constructor that creates initializes imu and makes it ready to supply data
     */
    IMU();

    /*!
     * This method returns true if sensor is working and false otherwise
     * @return the status of sensor running
     */
    bool isStarted();

    /*!
     * Specifies the settings for the gyroscope
     * @param scale is the full-scale range of gyroscope. It can be set to either 245, 500, or 2000
     * @param sampleRate is the output data rate of gyro. It can be set between 1 and 6
     * @param flipX switches the positive/negative orientation of x axis
     * @param flipY switches the positive/negative orientation of y axis
     * @param flipZ switches the positive/negative orientation of z axis
     */
    void setupGyro(uint8_t scale = 245, uint8_t sampleRate = 3, uint8_t flipX = (uint8_t)false,
                   uint8_t flipY = (uint8_t)false, uint8_t flipZ = (uint8_t)false);

    /*!
     * Specifies the settings for the accelerometer
     * @param scale is the full-scale range of accelerometer. It can be set to either 2, 4, 8 or 16
     * @param sampleRate is the output data range of accelerometer. It can be set between 1 and 6
     */
    void setupAccel(uint8_t scale = 8, uint8_t sampleRate = 1);

    /*!
     * Specifies the settings or the magnetometer
     * @param scale is the full scale range of magnetometer. It can be set to either 4, 8, 12 or 16
     * @param sampleRate is the output data rate of the magnetometer. It can be set between 0 and 7
     * @param tempComp enables or disables temperature compensation of the magnetometer
     * @param operatingMode sets the operating mode of magnetometer. It can be between 0 and 2
     */
    void setupMag(uint8_t scale = 12, uint8_t sampleRate = 5, uint8_t tempComp = (uint8_t)false,
                  uint8_t operatingMode = 0);

    /*!
     * Returns the x value of the component specified
     * @param comp is the component for which x value is needed. It can be IMU, MAG or ACCEL
     * @return the x value of that component
     */
    float getX(imu_comp comp);

    /*!
     * Returns the y value of the component specified
     * @param comp is the component for which x value is needed. It can be IMU, MAG or ACCEL
     * @return the y value of that component
     */
    float getY(imu_comp comp);

    /*!
     * Returns the z value of the component specified
     * @param comp is the component for which x value is needed. It can be IMU, MAG or ACCEL
     * @return the z value of that component
     */
    float getZ(imu_comp comp);
};


#endif //NEW_SENSORS_IMU_H
