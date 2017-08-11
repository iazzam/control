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

	const int numTimers = 5;

	const unsigned long controlRate = (1000000/30);
	const unsigned long cmdListenRate = (1000000/120);
	const unsigned long sensorReadRate = (1000000/260);
	const unsigned long connectionCheck = (1000000);
	const unsigned long watchdogReset = (200000);

	// number of prints and reads per second for each sensor
	const uint8_t COLOR_FREQ = 60;
	const uint8_t IMU_FREQ = 60;
	const uint8_t DPR_FREQ = 2;
	const uint8_t LOW_PRESSURE_FREQ = 30;
	const uint8_t PHOTO_FREQ = 30;
	const uint8_t MEM_FREQ = 2;
	const uint8_t TEMP_FREQ = 5;

	// io pins for subsystems
	const uint8_t ballValveRelayA = 3;
	const uint8_t ballValveRelayB = 4;
	const uint8_t dprRelay = 2;
	const uint8_t magFlp = 5;
	const uint8_t magFrp = 6;
	const uint8_t magRlp = 7;
	const uint8_t magRrp = 8;
	const uint8_t driveRelay = 9;
	const uint8_t drivePin = 10;
	const uint8_t dropRelay = 11;
	const uint8_t brakesRelay = 12;

	// for techometers
	const uint8_t flmSensor = 18;
	const uint8_t frmSensor = 19;
	const uint8_t rlmSensor = 20;
	const uint8_t rrmSensor = 21;

	// io pins for sensors
};

static Config config;

#endif //CONTROL_CONFIG_H
