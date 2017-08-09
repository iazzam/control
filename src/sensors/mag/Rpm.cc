#include <USBAPI.h>
#include "Rpm.h"

Rpm::Rpm(const String &name, const uint8_t rate, const uint8_t pin)
		:Sensor(name, rate, 1), pin{pin}{
	sensor = new Photoelectric{"rpmphoto", rate, pin};
	counts = 0;
	rps = rpm = 0;
	flag = true;
	lastTime = millis();
}

Rpm::~Rpm(){ delete sensor; }

float rpmCounter = 0;

float Rpm::read(){
	float distance = sensor->read();
	//add(distance);

	if (distance < 60 && flag){
		++counts;
		add(counts);
		flag = false;
	}

	if (distance >= 60){
		flag = true;
	}

	if (counts == 8){
		++rpmCounter;
	}

	if (millis() -  lastTime >= 1000){
		rpm = (60 / 8)*1000/(millis() - lastTime)*counts;
		lastTime = millis();
		counts = 0;
	}

	add(rpm);


	/*
	if (millis() - lastTime >= 100){
		avg += counts / 8.0;
		avg_counter++;

		if (avg_counter == 10) {
			rps = avg; // print this
			avg = 0;
			avg_counter = 0;
			//add(rps);
		}

		// 570
		// 565


		// rpm = rps * 60.0;
		//counts = 0;
		lastTime = millis();
	}
*/
	return get(0);
}

float Rpm::getRps(){
	return rps;
}

