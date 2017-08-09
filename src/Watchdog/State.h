/*!
 * @author Deep Dhillon
 * @date July 20, 2017
 * @brief This class contains the state of the pod
 */

#ifndef CONTROL_STATE_H
#define CONTROL_STATE_H

#include <Arduino.h>

class State {
public:
	// different modes to choose from
	static const uint8_t manual = 0;
	static const uint8_t autonomous = 1;
	static const uint8_t script = 2;

	// restart types to choose from
	static const uint8_t restartNone = 0;
	static const uint8_t restartSaved = 1;
	static const uint8_t restartUnsaved = 2;

	int mode = manual;
	int restart = restartNone;
	int emergency = (uint8_t) false;
	int stop = (uint8_t) false;
	int check = (uint8_t) true;

	int brakes = (uint8_t) false;
	int magSpeed = 0;
	int driveSpeed = 0;
	int drop = (uint8_t) false;
	int dpr = (uint8_t) false;
	int ballValve = (uint8_t) false;

	int heartbeatMiss = 0;
	bool reset = false;

	// magWheel stuff
	int servoLastSpeed = 1000;
	int servoGivenSpeed = 1000;
	int servoCurrSpeed = 1000;
	bool throttling = false;
	int throttleValue = 10;

	bool stateSaved = false;
};


#endif //CONTROL_STATE_H
