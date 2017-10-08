#include <Arduino.h>
#include <JsonHandler.h>
#include <Watchdog/State.h>
#include "SensorReader.h"
#include "Config.h"

long lastTime = millis();

SensorReader::SensorReader(State &state) : state(state){
	flmRpm = new Rpm{"rpmflm", static_cast<uint8_t>(260), config.flmSensor};
	frmRpm = new Rpm{"rpmfrm", static_cast<uint8_t>(260), config.frmSensor};
}

void SensorReader::read(){
	state.currRpmFL = flmRpm->read();

	if (millis() - lastTime >= 200){
		//wlp::serial << *flmRpm;
	}
}

SensorReader::~SensorReader(){
	delete flmRpm;
	delete frmRpm;
	delete rlmRpm;
	delete rrmRpm;
}
