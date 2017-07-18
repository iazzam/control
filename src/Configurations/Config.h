/*!
 * @file
 * @author Deep Dhillon
 * @date 2017-06-23
 * @brief This file holds all the configurations used by the code
 */

#include <WString.h>

#ifndef CONTROL_CONFIG_H
#define CONTROL_CONFIG_H

// commands for connection with pi
static const String CONNECT PROGMEM = "connect";
static const String PICHECK PROGMEM = "check";

// commands for overall pod functioning
static const String EMERGENCY PROGMEM = "emg";
static const String RESTARTS PROGMEM = "rests";
static const String RESTARTUS PROGMEM = "restus";
static const String STOP PROGMEM = "stop";
static const String AUTONOMOUS PROGMEM = "auto";
static const String MANUAL PROGMEM = "man";
static const String SCRIPT PROGMEM = "scpt";

// on and off components command
static const String BRAKE PROGMEM = "brk";
static const String BALLValve PROGMEM = "bv";
static const String DPR PROGMEM = "dpr";

// variable components command
static const String SPEED PROGMEM = "spd";


// Serial and timer configurations
static const long bandRate PROGMEM = 115200;            /*!< Serial bit rate being used */
static const int numTimers PROGMEM = 2;                 /*!< Number of timers being used */
/*!< Time interrupt in millis for executing commands */
static const unsigned long executeRate PROGMEM = (1000000/180);
/*!< Time interrupt in millis for checking the heartbeat of the pod */
static const unsigned long heartbeatRate PROGMEM = (1000000);


// number of prints and reads per second for each sensor
static const uint8_t COLOR_FREQ PROGMEM = 60;
static const uint8_t IMU_FREQ PROGMEM = 60;
static const uint8_t DPR_FREQ PROGMEM = 2;
static const uint8_t LOW_PRESSURE_FREQ PROGMEM = 30;
static const uint8_t PHOTO_FREQ PROGMEM = 30;
static const uint8_t MEM_FREQ PROGMEM = 2;
static const uint8_t TEMP_FREQ PROGMEM = 5;


// lev io pins
static const uint8_t LEV_RELAY_A = 11;         /*!< Lev Relay A pin */
static const uint8_t LEV_RELAY_B = 9;          /*!< Lev Relay B pin */
static const uint8_t DPR_RELAY_A = 12;         /*!< DPR Relay A pin */

#endif //CONTROL_CONFIG_H
