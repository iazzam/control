/*!
 * @file
 * @author Deep Dhillon
 * @date 2017-06-25
 * @brief This is the main file that will use Controller and Timer Pool to execute
 *        the program
 */



#include <Arduino.h>
#include <Timer/TimerPool.h>
#include "Controller.h"
#include <Watchdog/State.h>
#include <Watchdog/Watchdog.h>

TimerPool pool{numTimers};    /*!< Timer Pool contains Timers used to run parts at different times */

Controller *c;                /*!< Controller runs the pod as it contains the major code */

Watchdog watch;               /*!< Watchdog checks for frozen arduino and always keeps it running */

State s;                      /*!< State of the pod */


/*!
 * This resets the board and is passed to Controller for it to call
 */
void resetBoard(){
    watch.restartBoard(s);
}

/*!
 * Timer interrupt calls this function to execute the functioning of the pod. It uses
 * Controller's method to execute commands
 */

void execute() {
    c->control();
}

/*!
 * Heartbeat used to check connection with raspberry pi. If nothing is heard from PI,
 * stop procedure is started for the pod
 */
void check(){
    if (s.piCheck && !s.stopped){
        s.piCheck = false;
        s.stopped = false;
    }
    else
        s.stopped = true;
}


/*!
 *  Overridden from Arduino.h class and it holds the code to setup the Arduino when it runs
 */

void setup() {
    // add timer
    pool.addTimer(new TimerPool::Timer(executeRate, execute));
    pool.addTimer(new TimerPool::Timer(heartbeatRate, check));

    // get the state from the watchdog (this may be a saved state)
    s = watch.get();

    // start watchdog
    watch.setup();

    // create a controller
    c = new Controller{&s, resetBoard};

    // setup the controller
    c->setup();
}


/*!
 * Overriden from Arduino.h class and it updates Timers in a continuous loop and timers call
 * other parts of the code.
 */

void loop() {
    pool.handleTimers();
    watch.reset();
}

/*!
 * When watchdog resets the state of the pod is saved
 */
ISR(WDT_vect) {
    watch.add(s);
}
