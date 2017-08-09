#include <USBAPI.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "DriveTrain.h"

using namespace wlp;

DriveTrain::DriveTrain(const uint8_t relayPinDrive, const uint8_t analogPin,
                       const uint8_t relayPinDrop)
		: relayPinDrive{relayPinDrive}, analogPin{analogPin},
		  relayPinDrop{relayPinDrop}, dropped{false}{
	analogWrite(analogPin, 190);
}

void DriveTrain::control(const int speed){
	if (!shouldControl(speed)) return;

	int analogValue = 0;

	if (speed == 50) analogValue = 190;
	else if (speed < 50) analogValue = map(speed, 0, 49, 63, 184);
	else analogValue = map(speed, 51, 100, 191, 253);

	Serial.println(analogValue);

	if (speed < 50){
		serial << json.encodeMessage("Drive Train driving backwards");
	} else if (speed == 50){
		serial << json.encodeMessage("Drive Train stopped");
	} else if (speed > 50){
		serial << json.encodeMessage("Drive Train driving forward");
	}

	analogWrite(analogPin, analogValue);
}

void DriveTrain::drop(const Subsystem::BinaryState state){
	if (state == Subsystem::BinaryState::On){
		digitalWrite(relayPinDrop, HIGH);

		if (!dropped)
			serial << json.encodeMessage("drive Train dropped") << endl;

		dropped = true;
	} else{
		digitalWrite(relayPinDrop, LOW);

		if (dropped)
			serial << json.encodeMessage("drive Train picked up") << endl;

		dropped = false;
	}
}
