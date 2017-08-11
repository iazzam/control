#ifndef CONTROL_RPM_H
#define CONTROL_RPM_H

#include <sensors/Sensor.h>
#include <sensors/lev/Photoelectric.h>

class Rpm : public Sensor{
	const uint8_t pin;
	int rpm = 0;
	unsigned long lastMillis = 0;
public:
	Rpm(const String &name, const uint8_t rate, const uint8_t pin);

	float read();

	float getRps();
};

#endif //CONTROL_RPM_H
