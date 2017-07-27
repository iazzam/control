/*!
 * @file
 * @author Deep Dhillon
 * @date 2017-06-25
 * @brief This is the main file that will use Controller and Timer Pool to execute
 *        the program
 */

#include <Timer/TimerPool.h>
#include <Watchdog/Watchdog.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include "Controller.h"
#include "Config.h"


using namespace wlp;

TimerPool pool{config.numTimers};

Watchdog watch;

State s;

Controller *c;

/*!
 * Restarts the board and either save the state or not
 * @param save true or false based on if to save the state
 */
void resetBoard(bool save){
	s.restart = s.restartNone;

	if (save) watch.restartBoard(s);
	else watch.restartBoard();
}

/*!
 * Timer interrupt calls this function to execute the functioning of the pod. It uses
 * Controller's method to execute commands
 */
void execute() { c->control(); }

/*!
 * Heartbeat used to check connection with raspberry pi. If nothing is heard from PI,
 * stop procedure is started for the pod
 */
void check(){ c->check(); }

/*!
 *  Overridden from Arduino.h class and it holds the code to setup the Arduino when it runs
 */
void setup() {
	wlp::serial.begin(config.bandRate);

	// add timer
	pool.addTimer(new TimerPool::Timer(config.executeRate, execute));
	pool.addTimer(new TimerPool::Timer(config.heartbeatRate, check));


	// get the state from the watchdog (this may be a saved state)
	s = watch.get();

	// start watchdog
	watch.setup();

	// create a controller
	c = new Controller{s, resetBoard};

	// setup the controller
	c->setup();

	serial << json.encodeMessage("arduino booted up") << endl;
}

/*!
 * Overriden from Arduino.h class and it updates Timers in a continuous loop and
 * make timers call to other parts of the code.
 */
void loop() {
	pool.handleTimers();
	watch.reset();
}

/*!
 * When watchdog resets the state of the pod is saved
 */
ISR(WDT_vect) {
	serial << json.encodeMessage("watchdog restarting arduino") << endl;
	watch.add(s);
}
