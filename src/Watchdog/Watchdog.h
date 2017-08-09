/*!
 * @author Deep Dhillon
 * @date July 13 2017
 * @brief Watchdog for resetting the board in a case of freeze or when manually
 *        called reset from the software side
 */

#ifndef SENSORS_WATCHDOG_H
#define SENSORS_WATCHDOG_H

#include <EEPROM.h>
#include "State.h"

class Watchdog {
public:
    /*!
     * Creates Watchdog that will count for 1000ms before resetting
     */
    void setup();

    /*!
     * Reset the Watchdog clock so that watchdog does not detect a restart
     */
    void reset();

    /*!
     * Disables the watchdog
     */
    void disable();

    /*!
     * Stores state of the board in non volatile memory (EEPROM)
     * @param s is the State of the board
     */
    void add(State &s);

    /*!
     * Gets the state of the board from EEPROM. If arduino was manual reset
     * or power was cut off, it is considered a fresh start and new state is created
     * @return the State of the board
     */
    State get();

    /*!
     * Restarts the board as soon as possible. State of the board is saved
     * @param s is the state of the board
     */
    void restartBoard(State &s);

    /*!
     * Restarts the board as soon as possible. State of the board is not saved
     */
    void restartBoard();

};


#endif //SENSORS_WATCHDOG_H
