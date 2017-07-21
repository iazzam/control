/*!
 * @file
 * @author Deep Dhillon
 * @date 2017-06-23
 * @brief This file holds all the configurations used by the code
 */

#include <WString.h>

#ifndef CONTROL_CONFIG_H
#define CONTROL_CONFIG_H

class Config{
public:
    // commands for connection with pi
    const String CONNECT PROGMEM = "connect";
    const String PICHECK PROGMEM = "check";

    // commands for overall pod functioning
     const String EMERGENCY PROGMEM = "emg";
     const String RESTARTS PROGMEM = "rests";
     const String RESTARTUS PROGMEM = "restus";
     const String STOP PROGMEM = "stop";
     const String AUTONOMOUS PROGMEM = "auto";
     const String MANUAL PROGMEM = "man";
     const String SCRIPT PROGMEM = "scpt";

    // on and off components command
     const String BRAKE PROGMEM = "brk";
     const String BALLValve PROGMEM = "bv";
     const String DPR PROGMEM = "dpr";
     const String EMERGENCY_DRIVE PROGMEM = "edr";
     const String EMERGENCY_DROP PROGMEM = "ewr";

    // variable components command
     const String SPEED_DRIVE PROGMEM = "spddrive";
     const String SPEED_MAG PROGMEM = "spdmag";


    // Serial and timer configurations
     const long bandRate PROGMEM = 115200;            /*!< Serial bit rate being used */
     const int numTimers PROGMEM = 2;                 /*!< Number of timers being used */
    /*!< Time interrupt in millis for executing commands */
     const unsigned long executeRate PROGMEM = (1000000/180);
    /*!< Time interrupt in millis for checking the heartbeat of the pod */
     const unsigned long heartbeatRate PROGMEM = (1000000);


    // number of prints and reads per second for each sensor
     const uint8_t COLOR_FREQ PROGMEM = 60;
     const uint8_t IMU_FREQ PROGMEM = 60;
     const uint8_t DPR_FREQ PROGMEM = 2;
     const uint8_t LOW_PRESSURE_FREQ PROGMEM = 30;
     const uint8_t PHOTO_FREQ PROGMEM = 30;
     const uint8_t MEM_FREQ PROGMEM = 2;
     const uint8_t TEMP_FREQ PROGMEM = 5;


    // lev io pins
     const uint8_t LEV_RELAY_A = 11;         /*!< Lev Relay A pin */
     const uint8_t LEV_RELAY_B = 9;          /*!< Lev Relay B pin */
     const uint8_t DPR_RELAY_A = 12;         /*!< DPR Relay A pin */
};

#endif //CONTROL_CONFIG_H
