#include <USBAPI.h>
#include "Subsystem.h"

Subsystem::Subsystem(const bool constantApply)
		: constantApply{constantApply}, lastValue{0},
		  lastState{Subsystem::State::Off}{}

bool Subsystem::shouldControl(const int currentValue){
	if (constantApply) return true;

	if (currentValue == lastValue) return false;

	lastValue = currentValue;

	return true;
}

bool Subsystem::shouldControl(const Subsystem::State currentState){
	if (constantApply) return true;

	if (currentState == lastState) return false;

	lastState = currentState;

	return true;
}

void Subsystem::control(const Subsystem::State state){}

void Subsystem::control(const int value){}

int Subsystem::getLastValue(){ return lastValue; }

static Subsystem::State Subsystem::getState(uint8_t value){
	if ((bool)value) return Subsystem::State::On;
	else return Subsystem::State::Off;
}
