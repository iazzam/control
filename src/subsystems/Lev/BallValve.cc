#include "BallValve.h"
#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>

using namespace wlp;

BallValve::BallValve(const uint8_t relayPinA, const uint8_t relayPinB)
		: relayPinA{relayPinA}, relayPinB{relayPinB}{
	pinMode(relayPinA, OUTPUT);
	pinMode(relayPinB, OUTPUT);

	digitalWrite(relayPinA, LOW);
	digitalWrite(relayPinB, HIGH);
}

void BallValve::control(Subsystem::BinaryState state){
	if (!shouldControl(state)) return;

	if (state == Subsystem::BinaryState::On){
		serial << json.encodeMessage("ball valve state changed to on") << endl;
		digitalWrite(relayPinA, HIGH);
		digitalWrite(relayPinB, LOW);
	} else{
		serial << json.encodeMessage("ball valve state changed to off") << endl;
		digitalWrite(relayPinA, LOW);
		digitalWrite(relayPinB, HIGH);
	}
}
