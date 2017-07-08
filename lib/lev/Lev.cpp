/*
 *  Lev.cpp
 *
 *  Created on: June 17, 2017
 *  Author: Christopher
 *  Description: Implementation of the lev class
 */

#include "Lev.h"

Lev::Lev(int distance_pin, int dpr_pin) : distance_pin{distance_pin}, dpr_pin{dpr_pin}{

}

Lev::~Lev() {

}

int Lev::get_distance_raw() {
	return analogRead(distance_pin);
}

int Lev::get_DPR_raw() {
	return analogRead(dpr_pin);
}

float Lev::get_distance() {
	float scaled = get_distance_raw() / 1023.0 * (MAX_DISTANCE - MIN_DISTANCE);
	return scaled + MIN_DISTANCE;
}

float Lev::get_DPR() {
	float scaled = get_DPR_raw() / 1023.0 * (MAX_DPR - MIN_DPR);
	return scaled + MIN_DPR;
}

void Lev::print_distance() {
	float *comp_data = new float[1];
	comp_data[0] = get_distance();

	String name = "distance";

	Serial.println(data_handler.getJSONString(name, comp_data, 1));

	delete [] comp_data;
}

void Lev::print_DPR() {
	float *comp_data = new float[1];
	comp_data[0] = get_DPR();

	String name = "DPR";

	Serial.println(data_handler.getJSONString(name, comp_data, 1));

	delete [] comp_data;
}
