/*!
 * @name Deep Dhillon
 * @date July 11, 2017
 * @brief Library to access the raw IMU
 */

#ifndef SENSORS_SPARKFUNIMU_H
#define SENSORS_SPARKFUNIMU_H

#include <Arduino.h>
#include <SparkFunLSM9DS1.h>

class SparkfunIMU {
    const uint8_t LSM9DS1_M;
    const uint8_t LSM9DS1_AG;

    LSM9DS1 imu;

public:
	/*!
	 * Single constructor creates IMU sensor
	 * @param adrM address M for I2C
	 * @param adrAG address AG for I2C
	 */
    SparkfunIMU(uint8_t adrM=0x1E, uint8_t adrAG=0X6B);
	
	/*!
	 * Starts IMU sensor
	 * @return the status of the sensor
	 */
    bool begin();
	
	/*!
	 * Givess access to the raw IMU sensor
	 * @return the LSM9DS1 sensor object
	 */
    LSM9DS1 &getImu();
};


#endif //SENSORS_SPARKFUNIMU_H
