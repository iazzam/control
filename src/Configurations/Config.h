/*!
 * @file
 * @author Deep Dhillon
 * @date 2017-06-23
 * @brief This file holds all the configurations used by the code
 */

#ifndef CONTROL_CONFIG_H
#define CONTROL_CONFIG_H

// commands for overall pod functioning
static const String EMERGENCY PROGMEM = "emg";          /*!< Serial command for emergency */
static const String RESTART PROGMEM = "reset";          /*!< Serial command for restarting Arduino */
static const String AUTONOMOUS PROGMEM = "auto";        /*!< Serial command for autonomous */
static const String MANUAL PROGMEM = "man";             /*!< Serial command for manual */
static const String SCRIPT PROGMEM = "scpt";            /*!< Serial command for script */
static const String PICHECK PROGMEM = "check";          /*! < Serial command for heartbeat check with PI > */

// on and off components command
static const String STOP PROGMEM = "stop";              /*! < Serial command for stopping the pod > */
static const String BRAKE PROGMEM = "brk";              /*!< Serial command for brake */
static const String BALLValve PROGMEM = "bv";           /*!< Serial command for ball valve control */
static const String DPR PROGMEM = "dpr";                /*!< Serial command for dpr control */

// variable components command
static const String SPEED PROGMEM = "spd";              /*!< Serial command for ball valve control */


// Serial and timer configurations
static const long bandRate PROGMEM = 115200;            /*!< Serial bit rate being used */
static const int numTimers PROGMEM = 2;                 /*!< Number of timers being used */
/*!< Time interrupt in millis for executing commands */
static const unsigned long executeRate PROGMEM = (1000000/180);
/*!< Time interrupt in millis for checking the heartbeat of the pod */
static const unsigned long heartbeatRate PROGMEM = (3000000);


// lev constants
static const uint8_t LEV_RELAY_A = 11; /*!< Lev Relay A pin */
static const uint8_t LEV_RELAY_B = 9; /*!< Lev Relay B pin */
static const uint8_t DPR_RELAY_A = 12; /*!< DPR Relay A pin */

#endif //CONTROL_CONFIG_H
