#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "MagWheels.h"
#include "MagController.h"
#include <Watchdog/State.h>

using namespace wlp;

MagWheels::MagWheels(State &s, const uint8_t flp, const uint8_t frp, const uint8_t rlp,
                     const uint8_t rrp) : s(s){
	flServo.attach(flp);
	frServo.attach(frp);
	frServo.attach(rlp);
	frServo.attach(rrp);

	if (!s.stateSaved){
		flCurrValue = frCurrValue = rlCurrValue = rrCurrValue = 1270;
		flServo.writeMicroseconds(2000);
		flServo.writeMicroseconds(1000);
	}
}

void MagWheels::control(const float inc, uint8_t motor){
	if (motor == 0){
		flCurrValue = flCurrValue + inc;
		flServo.writeMicroseconds((int)flCurrValue);
	} else if (motor == 1){
		frCurrValue = frCurrValue + inc;
		frServo.writeMicroseconds((int)frCurrValue);
	} else if (motor == 2){
		rlCurrValue = rlCurrValue + inc;
		rlServo.writeMicroseconds((int)rlCurrValue);
	} else{
		rrCurrValue = rrCurrValue + inc;
		rrServo.writeMicroseconds((int)rlCurrValue);
	}
}

int MagWheels::getValue(uint8_t motorNum){
	if (motorNum == 0)
		return flCurrValue;
	else if (motorNum == 1)
		return frCurrValue;
	else if (motorNum == 2)
		return rlCurrValue;
	else
		return rrCurrValue;
}
