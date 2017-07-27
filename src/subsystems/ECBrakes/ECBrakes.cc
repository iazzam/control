#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "ECBrakes.h"

using namespace wlp;

ECBrakes::ECBrakes(const uint8_t relayPin) : relayPin{relayPin}{
	pinMode(relayPin, OUTPUT);
}

void ECBrakes::control(Subsystem::State state){
	if (!shouldControl(state)) return;

	if (state == Subsystem::State::On){
		digitalWrite(relayPin, true);
		serial << json.encodeMessage("ec brakes state changed to on") << endl;
	} else{
		digitalWrite(relayPin, false);
		serial << json.encodeMessage("ec brakes state changed to off") << endl;
	}
}
