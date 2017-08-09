#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "MagWheels.h"
#include <Watchdog/State.h>

using namespace wlp;

MagWheels::MagWheels(State &s, const uint8_t flp, const uint8_t frp, const uint8_t rlp,
                     const uint8_t rrp) : s(s){
	flServo.attach(flp);
	frServo.attach(frp);
	rlServo.attach(rlp);
	rrServo.attach(rrp);

	servoCurrSpeed = s.servoCurrSpeed;
	servoLastSpeed = s.servoLastSpeed;
	throttling = s.throttling;
	throttleValue = s.throttleValue;
	servoGivenSpeed = s.servoGivenSpeed;

	if (!s.stateSaved){
		// calibrate each motor
		flServo.writeMicroseconds(2000);
		flServo.writeMicroseconds(1000);

		frServo.writeMicroseconds(2000);
		frServo.writeMicroseconds(1000);

		rlServo.writeMicroseconds(2000);
		rlServo.writeMicroseconds(1000);

		rrServo.writeMicroseconds(2000);
		rrServo.writeMicroseconds(1000);
	}
}

void MagWheels::throttle(){
	servoCurrSpeed += throttleValue;

	if (!slowingDown && servoCurrSpeed > servoGivenSpeed){
		throttling = false;
		servoCurrSpeed -= throttleValue;
		return;
	} else if (slowingDown && servoCurrSpeed < servoGivenSpeed){
		throttling = false;
		servoCurrSpeed -= throttleValue;
		return;
	}

	flServo.writeMicroseconds(servoCurrSpeed);
	frServo.writeMicroseconds(servoCurrSpeed);
	rlServo.writeMicroseconds(servoCurrSpeed);
	rrServo.writeMicroseconds(servoCurrSpeed);
}

void MagWheels::control(const int speed){
	int lastValue = getLastValue();

	if (!shouldControl(speed)){
		if (throttling) {
			throttle();
		}
		return;
	}

	// convert the speed to the speed accepted by the servo
	servoGivenSpeed = speed + 1000;
	servoLastSpeed =  lastValue + 1000;

	slowingDown = servoLastSpeed > servoGivenSpeed;
	throttling = true;

	throttleValue = abs(throttleValue);

	if (slowingDown) throttleValue *= -1;

	if (slowingDown){
		serial << json.encodeMessage("Mag Wheels are slowing down to speed "
		                             + String(speed)) << endl;
	} else{
		serial << json.encodeMessage("Mag Wheels are speeding up to speed "
		                             + String(speed)) << endl;
	}
}
