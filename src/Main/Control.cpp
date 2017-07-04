/*!
 * @file
 * @author Deep Dhillon
 * @date 2017-06-25
 * @brief This is the main file that will use Controller and Timer Pool to execute
 *        the program
 */


#include <Arduino.h>
#include <Timer/TimerPool.h>
#include <Configurations/Config.h>
#include "Controller.h"

TimerPool pool{num_timers}; /*!< Timer Pool contains Timers used to run parts at different times */
Controller c{band_rate}; /*!< Controller runs the pod as it contains the major code */

/*!
 * Timer interrupt calls this function to execute reading Commands. It uses
 * Controller's method to read commands
 */
void readCommands(){
    c.handleCommands();
}

// will make decisions and run everything
/*!
 * Timer interrupt calls this function to execute the functioning of the pod. It uses
 * Controller's method to execute commands
 */
void execute(){
    c.control();
}

/*!
 *  Overriden from Arduino.h class and it holds the code to setup the Arduino when it runs
 */
void setup(){
    // add timers
    pool.addTimer(new TimerPool::Timer(parse_rate, readCommands));
    pool.addTimer(new TimerPool::Timer(execute_rate, execute));

    // setup the controller
    c.setup();
}

/*!
 * Overriden from Arduino.h class and it updates Timers in a continuous loop and timers call
 * other parts of the code.
 */
void loop(){
    pool.handleTimers();
}