#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "ECBrakes.h"

using namespace wlp;

ECBrakes::ECBrakes(const uint8_t relayPin) : relayPin{relayPin}{
	pinMode(relayPin, OUTPUT);
}

void ECBrakes::control(Subsystem::BinaryState state){
	if (!shouldControl(state)) return;

	if (state == Subsystem::BinaryState::On){
		digitalWrite(relayPin, HIGH);
		serial << json.encodeMessage("ec brakes state changed to on") << endl;
	} else{
		digitalWrite(relayPin, LOW);
		serial << json.encodeMessage("ec brakes state changed to off") << endl;
	}
}
