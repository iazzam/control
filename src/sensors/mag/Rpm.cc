#include <Arduino.h>
#include <USBAPI.h>
#include "Rpm.h"

boolean flag = false;

volatile int rpmCount = 0;

void rpmInc();

Rpm::Rpm(const String &name, const uint8_t rate, const uint8_t pin)
		:Sensor(name, rate, 1), pin{pin}{
	attachInterrupt(digitalPinToInterrupt(pin), rpmInc, FALLING);
	pinMode(pin, INPUT);
}

float Rpm::read(){
	/*
	int value = digitalRead(pin);

	if (value == 1 && flag){
		++rpmCount;
		//Serial.println("Got it: " + String(rpmCount));
		flag = false;
	}

	if (value == 0){
		flag = true;
	}
	 */

	if (millis() - lastMillis >= 250){
		detachInterrupt(digitalPinToInterrupt(pin));

		rpm = rpmCount * (240 / 8);
		rpmCount = 0;
		lastMillis = millis();
		attachInterrupt(digitalPinToInterrupt(pin), rpmInc, FALLING);
	}

	add(rpm);
	return get(0);
}

void rpmInc(){
	++rpmCount;
	//Serial.println("Got it: " + String(rpmCount));
}

float Rpm::getRps(){
	return rpm;
}
