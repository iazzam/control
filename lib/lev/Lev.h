/*
 * Lev.h
 *
 *  Created on: June 17, 2017
 *  Author: Christopher
 *  Description: Lev has the levitation related sensors.
 */

#ifndef SRC_LEVSUBSYSTEM_H_
#define SRC_LEVSUBSYSTEM_H_

#include "shared/DataHandler.h"

class Lev {
private:
    const float MIN_DISTANCE = 20; //millimeters
    const float MAX_DISTANCE = 80; 

    const float MIN_DPR = 100; // TODO: NOT ACCURATE VALUES
    const float MAX_DPR = 200;

    DataHandler data_handler;
    int distance_pin;
    int dpr_pin;

public:
    Lev(int distance_pin, int dpr_pin);

    ~Lev();

    // Outputs the distance voltage in JSON format.
    void print_distance();

    // Outputs the DPR voltage in JSON format.
    void print_DPR();

    // Gets the distance voltage as measured by the photoelectric distance sensor
    // (0V-5V. 0-1023)
    int get_distance_raw();

    // Gets the DPR pressure value 
    // (0V-5V, 0-1023)
    int get_DPR_raw();

    // Returns the distance in millimeters.
    // Linearly scaled from MIN_DISTANCE to MAX_DISTANCE
    float get_distance();

    // Returns the pressure in ???.
    // Linearly scaled from MIN_DPR to MAX_DPR;
    float get_DPR();
};

#endif
