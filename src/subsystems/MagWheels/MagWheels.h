/*!
 * @author Deep Dhillon
 * @date July 20, 2017
 * @brief This library is used to control Mag Wheels
 */

#ifndef CONTROL_NEW_MAGWHEELS_H
#define CONTROL_NEW_MAGWHEELS_H

#include <stdint.h>
#include <subsystems/Subsystem.h>
#include <Servo.h>

class MagWheels : public Subsystem{
	Servo flServo;
	Servo frServo;
	Servo rlServo;
	Servo rrServo;
public:
	/*!
	 * Single Constructor creates MagWheels
	 * @param flp motor controller pin for front left motor
	 * @param frp motor controller pin for front right motor
	 * @param rlp motor controller pin for rear left motor
	 * @param rrp motor controller pin for rea right motor
	 */
	MagWheels(const uint8_t flp, const uint8_t frp, const uint8_t rlp,
	          const uint8_t rrp);

	/*!
	 * Controls mag wheels' speed based on the speed provided
	 * @param speed speed of mag wheels
	 */
	void control(const int speed);
};

#endif //CONTROL_NEW_MAGWHEELS_H
