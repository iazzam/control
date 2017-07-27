#include "BallValve.h"
#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>

using namespace wlp;

BallValve::BallValve(const uint8_t relayPinA, const uint8_t relayPinB)
		: relayPinA{relayPinA}, relayPinB{relayPinB}{
	pinMode(relayPinA, OUTPUT);
	pinMode(relayPinB, OUTPUT);
}

void BallValve::control(Subsystem::State state){
	if (!shouldControl(state)) return;

	if (state == Subsystem::State::On){
		serial << json.encodeMessage("ball valve state changed to on") << endl;
		digitalWrite(relayPinA, true);
		digitalWrite(relayPinA, false);
	} else{
		serial << json.encodeMessage("ball valve state changed to off") << endl;
		digitalWrite(relayPinA, false);
		digitalWrite(relayPinA, true);
	}
}
