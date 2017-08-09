#ifndef CONTROL_SENSORREADER_H
#define CONTROL_SENSORREADER_H

#include <sensors/mag/Rpm.h>

class State;

class SensorReader{
	State &state;
	Rpm *flmRpm;
	Rpm *frmRpm;
	Rpm *rrmRpm = nullptr;
	Rpm *rlmRpm = nullptr;
public:
	SensorReader(State &state);

	~SensorReader();

	void read();
};

#endif //CONTROL_SENSORREADER_H
