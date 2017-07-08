/*!
 * @author Deep Dhillon
 * @date 2017-05-27
 * @brief This class holds number of IMU sensors' objects and handles data from all of them. It provides
 * access to data in both JSON and raw format
 */


#ifndef SRC_IMUSUBSYSTEM_H_
#define SRC_IMUSUBSYSTEM_H_

#include "IMU.h"
#include "../shared/DataHandler.h"


class IMUPool {
private:
    const unsigned int sensor_total;

    IMU **sensors;
    DataHandler data_handler;

public:
    /*!
     * Single constructor which creates multiple imus and initialize them
     * @param num_sensors is the number of sensors to be created
     */
    IMUPool(unsigned int num_sensors);

    /*!
     * Destructor deletes all the imu sensors and frees up memory
     */
    ~IMUPool();

    /*!
     * This method returns true if all sensors are working and false otherwise
     * @return the status of all the imus running
     */
    bool sensorsWorking();

    /*!
     * Prints data to Serial of a particular component of a particular imu in JSON format
     * @param sensor is the imu sensor from which data should be printed
     * @param component is the component from that particular imu. It could be GYRO, ACCEL or MAG
     */
    void serialPrint(unsigned int sensor, imu_comp component);

    /*!
     * Gives access to number of sensors being used
     * @return the number of sensors being used
     */
    int getTotal();

    /*!
     * Returns the x value of the component specified from the imu specified
     * @param system is the imu sensor from which data should be gathered
     * @param component is the component for which x value is needed. It can be IMU, MAG or ACCEL
     * @return the x value of that component
     */
    float getX(unsigned int system, imu_comp component);

    /*!
     * Returns the y value of the component specified from the imu specified
     * @param system is the imu sensor from which data should be gathered
     * @param component is the component for which x value is needed. It can be IMU, MAG or ACCEL
     * @return the y value of that component
     */
    float getY(unsigned int system, imu_comp component);

    /*!
     * Returns the z value of the component specified from the imu specified
     * @param system is the imu sensor from which data should be gathered
     * @param component is the component for which x value is needed. It can be IMU, MAG or ACCEL
     * @return the z value of that component
     */
    float getZ(unsigned int system, imu_comp component);
};

#endif
