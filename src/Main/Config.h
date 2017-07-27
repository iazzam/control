/*!
 * @file
 * @author Deep Dhillon
 * @date 2017-06-23
 * @brief This file holds all the configurations used by the code
 */

#include <WString.h>

#ifndef CONTROL_CONFIG_H
#define CONTROL_CONFIG_H

class Config{
public:

	// Serial and timer configurations
	const long bandRate = 115200;

	const int numTimers = 2;

	const unsigned long executeRate = (1000000/180);

	const unsigned long heartbeatRate = (500000000);

	// number of prints and reads per second for each sensor
	const uint8_t COLOR_FREQ = 60;
	const uint8_t IMU_FREQ = 60;
	const uint8_t DPR_FREQ = 2;
	const uint8_t LOW_PRESSURE_FREQ = 30;
	const uint8_t PHOTO_FREQ = 30;
	const uint8_t MEM_FREQ = 2;
	const uint8_t TEMP_FREQ = 5;

	// io pins for subsystems
	const uint8_t ballValveRelayA = 0;
	const uint8_t ballValveRelayB = 1;
	const uint8_t dprRelay = 2;
	const uint8_t magFlp = 3;
	const uint8_t magFrp = 4;
	const uint8_t magRlp = 5;
	const uint8_t magRrp = 6;
	const uint8_t driveRelayA = 7;
	const uint8_t driveRelayB = 8;
	const uint8_t dropRelay = 9;
	const uint8_t brakesRelay = 10;

	// io pins for sensors
};

static Config config;

#endif //CONTROL_CONFIG_H
