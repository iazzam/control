#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "DPR.h"

using namespace wlp;

DPR::DPR(const uint8_t relayPin) : relayPin{relayPin}{
	pinMode(relayPin, OUTPUT);
}

void DPR::control(Subsystem::BinaryState state){
	if (!shouldControl(state)) return;

	if (state == Subsystem::BinaryState::On){
		digitalWrite(relayPin, HIGH);
		serial << json.encodeMessage("dpr state changed to on") << endl;
	} else{
		digitalWrite(relayPin, LOW);
		serial << json.encodeMessage("dpr state changed to off") << endl;
	}
}
