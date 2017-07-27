#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "MagWheels.h"

using namespace wlp;

MagWheels::MagWheels(const uint8_t flp, const uint8_t frp, const uint8_t rlp,
                     const uint8_t rrp) {
	flServo.attach(flp);
	frServo.attach(frp);
	rlServo.attach(rlp);
	rrServo.attach(rrp);

	// calibrate each motor
	flServo.writeMicroseconds(2000);
	flServo.writeMicroseconds(1000);

	frServo.writeMicroseconds(2000);
	frServo.writeMicroseconds(1000);

	rlServo.writeMicroseconds(2000);
	rlServo.writeMicroseconds(1000);

	rrServo.writeMicroseconds(2000);
	rrServo.writeMicroseconds(1000);

	serial << "Value: " << getLastValue() << endl;
}

void MagWheels::control(const int speed){
	int lastValue = getLastValue();

	if (!shouldControl(speed)) return;

	String message = "";

	if (lastValue >= speed){
		for (int i = lastValue; i >= speed; --i) {
			int val = map(i, 0, 100, 1000, 2000);

			flServo.writeMicroseconds(val);
			frServo.writeMicroseconds(val);
			rlServo.writeMicroseconds(val);
			rrServo.writeMicroseconds(val);

			delay(7);
		}
		message = "mag speed decreased to " + String(speed);
	} else{
		for (int i = lastValue; i <= speed; ++i) {
			int val = map(i, 0, 100, 1000, 2000);

			flServo.writeMicroseconds(val);
			frServo.writeMicroseconds(val);
			rlServo.writeMicroseconds(val);
			rrServo.writeMicroseconds(val);
			
			delay(7);
		}
		message = "mag speed increased to " + String(speed);
	}

	serial << json.encodeMessage(message) << endl;
}
