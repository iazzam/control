#include <USBAPI.h>
#include "Subsystem.h"

Subsystem::Subsystem(const bool constantApply)
		: constantApply{constantApply}, lastValue{0},
		  lastState{Subsystem::BinaryState::Off}{}

bool Subsystem::shouldControl(const int currentValue){
	if (constantApply) return true;

	if (currentValue == lastValue) return false;

	lastValue = currentValue;

	return true;
}

bool Subsystem::shouldControl(const Subsystem::BinaryState currentState){
	if (constantApply) return true;

	if (currentState == lastState) return false;

	lastState = currentState;

	return true;
}

void Subsystem::control(const Subsystem::BinaryState state){}

void Subsystem::control(const int value){}

int Subsystem::getLastValue(){ return lastValue; }

Subsystem::BinaryState Subsystem::getState(uint8_t value){
	if ((bool)value) return Subsystem::BinaryState::On;
	else return Subsystem::BinaryState::Off;
}
