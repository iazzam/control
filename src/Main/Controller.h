/*!
 * @author Deep Dhillon
 * @date 2017-06-25
 * @brief This class is used to control the pod and provide for an interface to make everything work
 */

#ifndef CONTROL_NEW_CONTROLLER_H
#define CONTROL_NEW_CONTROLLER_H

#include <Commands/CommandListener.h>
#include <subsystems/Lev/BallValve.h>
#include <subsystems/Lev/DPR.h>
#include <subsystems/MagWheels/MagWheels.h>
#include <subsystems/DriveTrain/DriveTrain.h>
#include <subsystems/ECBrakes/ECBrakes.h>

class SensorReader;

class Controller{
	State &state;                   // state of the pod

	SensorReader &reader;           // listener for commands

	void(*restart)(bool);           // function to restart the board

	// create subsystem objects
	BallValve *ballValve;
	DPR *dpr;
	MagWheels *magWheels;
	DriveTrain *driveTrain;
	ECBrakes *brakes;

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
     * Single Constructor creates the Controller
     * @param state State of the pod to use
     * @param reset function to restart the board
     */
	Controller(State &state, SensorReader &reader, void(*reset)(bool));

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
	 * This method is a heartbeat that will check if the connection wil Pi is still
	 * maintained
	 */
	void check();

	/*!
	 * This method is used to stop the pod. It contains the code to stop necessary
	 * components and stop the pod
	 */
	void stop();
};

#endif //CONTROL_NEW_CONTROLLER_H
