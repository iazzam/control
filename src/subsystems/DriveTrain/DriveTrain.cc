#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "DriveTrain.h"

using namespace wlp;

DriveTrain::DriveTrain(const uint8_t relayPinDriveA, const uint8_t relayPinDriveB,
                       const uint8_t relayPinDrop)
		: relayPinDriveA{relayPinDriveA}, relayPinDriveB{relayPinDriveB},
		  relayPinDrop{relayPinDrop}, dropped{false}{
	pinMode(relayPinDriveA, OUTPUT);
	pinMode(relayPinDriveB, OUTPUT);
	pinMode(relayPinDrop, OUTPUT);
}

void DriveTrain::control(const int speed){
	if (!shouldControl(speed)) return;

	if (speed > 50){
		digitalWrite(relayPinDriveA, true);
		digitalWrite(relayPinDriveB, false);
		serial << json.encodeMessage("drive Train is driving forward") << endl;
	} else if (speed < 50){
		digitalWrite(relayPinDriveA, false);
		digitalWrite(relayPinDriveB, true);
		serial << json.encodeMessage("drive Train is driving backwards") << endl;
	} else{
		digitalWrite(relayPinDriveA, false);
		digitalWrite(relayPinDriveB, false);
		serial << json.encodeMessage("drive Train stopped driving") << endl;
	}
}

void DriveTrain::drop(const Subsystem::State state){
	if (state == Subsystem::State::On){
		digitalWrite(relayPinDrop, true);

		if (!dropped)
			serial << json.encodeMessage("drive Train dropped") << endl;

		dropped = true;
	} else{
		digitalWrite(relayPinDrop, false);

		if (dropped)
			serial << json.encodeMessage("drive Train picked up") << endl;

		dropped = false;
	}
}
