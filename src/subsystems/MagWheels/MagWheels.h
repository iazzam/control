/*!
 * @author Deep Dhillon
 * @date July 20, 2017
 * @brief This library is used to control Mag Wheels
 */

#ifndef CONTROL_NEW_MAGWHEELS_H
#define CONTROL_NEW_MAGWHEELS_H

#include <stdint.h>
#include <subsystems/Subsystem.h>
#include <ESC.h>

class State;

class MagWheels : public Subsystem{
	Servo flServo;
	Servo frServo;
	Servo rlServo;
	Servo rrServo;

	float flCurrValue;
	float frCurrValue;
	float rlCurrValue;
	float rrCurrValue;

	State &s;

public:
	/*!
	 * Single Constructor creates MagWheels
	 * @param flp motor controller pin for front left motor
	 * @param frp motor controller pin for front right motor
	 * @param rlp motor controller pin for rear left motor
	 * @param rrp motor controller pin for rea right motor
	 */
	MagWheels(State &s, const uint8_t flp, const uint8_t frp, const uint8_t rlp,
	          const uint8_t rrp);

	/*!
	 * Controls mag wheels' speed based on the speed provided
	 * @param speed speed of mag wheels
	 */
	void control(const float speed, uint8_t motorNum);

	/*!
	 * Gives slowly increase and decrease in speed to the motor for gradual
	 * speed increase
	 */
	int getValue(uint8_t motorNum);
};

#endif //CONTROL_NEW_MAGWHEELS_H
