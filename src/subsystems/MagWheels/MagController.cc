#include <Main/Config.h>
#include "MagController.h"
#include <Watchdog/State.h>

MagController::MagController(MagWheels &wheels, State &s) : wheels{wheels}, s(s){
	inc = .2;
	lastTime = millis();
}

bool greater(const long desired, const float curr){
	return desired - curr >= 20;
}

bool lesser(const long desired, const float curr){
	return curr - desired >= 20;
}

void MagController::control(int percentage){
	long desiredRpm = map(percentage, 0, 100, 0, MAX_RPM);

	if (!shouldControl(percentage)){

		if (throttling) {
			throttle(desiredRpm);
		}
		return;
	} else{
		Serial.println("Rpm: " + String(desiredRpm));
		flag1 = flag2 = flag3 = flag4 = true;
		throttling = true;
	}
}

void MagController::throttle(long desiredRpm){
	if (greater(desiredRpm, s.currRpmFL)) adjustSpeed(desiredRpm, s.currRpmFL, Movement::INCREASE, Wheels::FRONT_LEFT);
	else if (lesser(desiredRpm, s.currRpmFL))  adjustSpeed(desiredRpm, s.currRpmFL, Movement::DECREASE, Wheels::FRONT_LEFT);
	else flag1 = false;

	if (greater(desiredRpm, s.currRpmFR)) adjustSpeed(desiredRpm, s.currRpmFR, Movement::INCREASE, Wheels::FRONT_RIGHT);
	else if (lesser(desiredRpm, s.currRpmFR)) adjustSpeed(desiredRpm, s.currRpmFR, Movement::DECREASE, Wheels::FRONT_RIGHT);
	else flag2 = false;

	if (greater(desiredRpm, s.currRpmRL)) adjustSpeed(desiredRpm, s.currRpmRL, Movement::INCREASE, Wheels::REAR_LEFT);
	else if (lesser(desiredRpm, s.currRpmRL)) adjustSpeed(desiredRpm, s.currRpmRL, Movement::DECREASE, Wheels::REAR_LEFT);
	else flag3 = false;

	if (greater(desiredRpm, s.currRpmRR)) adjustSpeed(desiredRpm, s.currRpmRR, Movement::INCREASE, Wheels::REAR_RIGHT);
	else if (lesser(desiredRpm, s.currRpmRR)) adjustSpeed(desiredRpm, s.currRpmRR, Movement::DECREASE, Wheels::REAR_RIGHT);
	else flag4 = false;

	if (!flag1 && !flag2 && !flag3 && !flag4) throttling = false;
}

void MagController::adjustSpeed(long desiredRpm, float currRpm,
                                MagController::Movement movement,
                                MagController::Wheels wheelsGiven){

	if (movement == Movement::INCREASE) inc = abs(inc);
	else inc = abs(inc) * -1;

	if (wheelsGiven == Wheels::FRONT_LEFT){
		Serial.println("I am adjusting: " + String(desiredRpm) + "  " + String(currRpm));
		wheels.control(inc, 0);
		Serial.println("Value: " + String(wheels.getValue(0)));
	} else if (wheelsGiven == Wheels::FRONT_RIGHT){
		wheels.control(inc, 1);
	} else if (wheelsGiven == Wheels::REAR_LEFT){
		wheels.control(inc, 2);
	} else{
		wheels.control(inc, 3);
	}
}

