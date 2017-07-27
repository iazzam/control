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

	uint8_t mode = 0;
	uint8_t restart = restartNone;
	uint8_t emergency = (uint8_t) false;
	uint8_t stop = (uint8_t) true;
	uint8_t check = (uint8_t) true;

	uint8_t brakes = (uint8_t) false;
	uint8_t magSpeed = 0;
	uint8_t driveSpeed = 0;
	uint8_t drop = (uint8_t) false;
	uint8_t dpr = (uint8_t) false;
	uint8_t ballValve = (uint8_t) false;

	uint8_t heartbeatMiss = 0;
	bool reset = false;
};


#endif //CONTROL_STATE_H
