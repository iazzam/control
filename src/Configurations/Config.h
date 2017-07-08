/*!
 * @file
 * @author Deep Dhillon
 * @date 2017-06-23
 * @brief This file holds all the configurations used by the code
 */

#ifndef CONTROL_CONFIG_H
#define CONTROL_CONFIG_H

// commands received from pi
static const String EMERGENCY = "emg"; /*!< Serial command for emergency */
static const String BRAKE = "brk"; /*!< Serial command for brake */
static const String SPEED = "spd"; /*!< Serial command for ball valve control */
static const String BALLValve = "bv"; /*!< Serial command for script */
static const String AUTONOMOUS = "auto"; /*!< Serial command for autonomous */
static const String MANUAL = "man"; /*!< Serial command for manual */
static const String SCRIPT = "scpt"; /*!< Serial command for script */


// Serial and timer configurations
static const long band_rate = 115200; /*!< Serial bit rate being used */
static const int num_timers = 2; /*!< Number of timers being used */
static const unsigned long execute_rate = (1000000/180); /*!< Time interrupt in millis for executing commands */
static const unsigned long parse_rate = (1000000/120); /*!< Time interrupt in millis for parsing commands */

// configurations for subsystems


// lev constants
static const uint8_t LEV_RELAY_A = 8; /*!< Lev Relay A pin */
static const uint8_t LEV_RELAY_B = 9; /*!< Lev Relay B pin */

#endif //CONTROL_CONFIG_H
