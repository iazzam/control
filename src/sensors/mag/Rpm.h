#ifndef CONTROL_RPM_H
#define CONTROL_RPM_H

#include <sensors/Sensor.h>
#include <sensors/lev/Photoelectric.h>

class Rpm : public Sensor{
	const uint8_t pin;
	int counts;
	float rps;
	float rpm;
	bool flag;
	long lastTime;
	Photoelectric *sensor;

	float avg = 0;
	int avg_counter = 0;

public:
	Rpm(const String &name, const uint8_t rate, const uint8_t pin);

	~Rpm();

	float read();

	float getRps();

	bool shouldPrint();
};

#endif //CONTROL_RPM_H
