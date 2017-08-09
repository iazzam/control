#include <Arduino.h>
#include "SensorReader.h"

long lastTime = millis();

SensorReader::SensorReader(State &state) : state(state){
	flmRpm = new Rpm{"leftRpm", 1, A0};
	frmRpm = new Rpm{"rightRpm", 1, A1};//new Rpm{"leftRpm", 1, A1};
}

void SensorReader::read(){
	float val1 = flmRpm->read();
	float val2 = frmRpm->read();

	if (millis() - lastTime >= 1000){
		wlp::serial << val1 << "," << val2 << wlp::endl;
		lastTime = millis();
	}

	//Serial.print(val1, 8);
	//Serial.print(" ");
	//Serial.println(val2, 8);

	//wlp::serial << val1 << " " << val2 << wlp::endl;
}

SensorReader::~SensorReader(){
	delete flmRpm;
	delete frmRpm;
	delete rlmRpm;
	delete rrmRpm;
}
