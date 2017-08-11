#ifndef CONTROL_MAGCONTROLLER_H
#define CONTROL_MAGCONTROLLER_H

#include <sensors/mag/Rpm.h>
#include "MagWheels.h"

class MagController: public Subsystem{
	MagWheels &wheels;
	float inc;

#define MAX_RPM 7500

	enum class Wheels{
		FRONT_LEFT,
		FRONT_RIGHT,
		REAR_LEFT,
		REAR_RIGHT
	};

	enum class Movement{
		INCREASE,
		DECREASE
	};

	long lastTime;

	bool flag1 = true;

	bool flag2 = true;

	bool flag3 = true;

	bool flag4 = true;

	bool throttling = false;

	State &s;

public:
	MagController(MagWheels &wheels, State &s);

	void throttle(long desiredRpm);

	void adjustSpeed(long desiredRpm, float currRpm, Movement movement, Wheels wheels);

	void control(int percentage);
};

#endif //CONTROL_MAGCONTROLLER_H
