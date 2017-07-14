/*!
 * @author Deep Dhillon
 * @date 2017-06-25
 * @brief This class is used to control the pod and provide for an interface to make everything work
 */

#ifndef CONTROL_POD_CONTROLLER_H
#define CONTROL_POD_CONTROLLER_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <Configurations/Config.h>
#include <WSerial.h>
#include <Watchdog/State.h>
#include <Timer/TimerPool.h>
#include <Listeners/CommandListener.h>


class Controller {
    // Field for State object
    State *s;

    void (*resetBoard)();

    // serial objects
    WSerial serial;

    // command listener
    CommandListener listener{s};


    /*!
     * Handles the case when there is emergency and an action has to be taken. This
     * has the top most priority and is executed as quickly as possible
     */
    void emergencyProtocol();

    /*!
     * Handles all the manual controls for the pod. This allows us to
     * manually adjust various features of the pod from the control panel
     */
    void handleManual();

    /*!
     * Allows us to run a script when we need to test something. The code will keep executing
     * what is defined in this function
     */
    void handleScript();

    /*!
     * Handles all the manual controls for the pod. This allows us to
     * manually adjust various features of the pod from the control panel
     */
    void handleAutonomous();
public:
    /*!
     * The only constructor for this class. It uses bit rate to determine the
     * data flow rate of Serial connection
     * @param band_rate bit rate of Serial connection
     */
    Controller(State *s, void(*reset)());

    /*!
     * Destructor deletes all the subsystems on the pod when Control
     * goes off the scope
     */
    ~Controller();

    /*!
     * This method holds the code that will be run at the beginning. Is used
     * for initializing various pod parts
     */
    void setup();


    /*!
     * This method acts as a loop that controls the working of the pod. It handles
     * various function modes like: Autonomous, Manual and Script
     */
    void control();

    /*!
     * This method is used to stop the pod. It contains the code to stop necessary
     * components and stop the pod
     */
    void stop();
};


#endif //CONTROL_POD_CONTROLLER_H
