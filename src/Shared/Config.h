//
// Created by Deep on 2017-06-23.
// Description: All the configurations will be in this file
//

#ifndef CONTROL_CONFIG_H
#define CONTROL_CONFIG_H

// commands received from pi
static const String EMERGENCY = "Emergency Stop";
static const String BRAKE = "Brake";
static const String SPEED = "Speed";
static const String Autonomous = "Autonomous";
static const String LEV = "Ball Valve";


// lev constants
static const int LEV_RELAY_A = 7;
static const int LEV_RELAY_B = 3;


// imu sensors




// controlled loop related variables
//static const unsigned int board_freq;    // 16MHz
static const unsigned long function_rate = (1000000/120);   // 120 times per second
static const unsigned long sensor_read_rate = (1000000/60); // 60 times per second
static const unsigned long bit_rate = 115200;


#endif //CONTROL_CONFIG_H
