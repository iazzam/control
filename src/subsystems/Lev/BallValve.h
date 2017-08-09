/*!
 * @authors Deep Dhillon Christopher
 * @date June 10, 2017
 * @brief This library is used to control levitation's ball valve system
 */

#ifndef CONTROL_NEW_BALLVALVE_H
#define CONTROL_NEW_BALLVALVE_H

#include <subsystems/Subsystem.h>

class BallValve : public Subsystem{
	const uint8_t relayPinA;
	const uint8_t relayPinB;
public:
	/*!
	 * Single constructor creates BallValve
	 * @param relayPinA the relay pin 1 ball valve is attached to
	 * @param relayPinB the relay pin 2 ball valve is attached to
	 */
	BallValve(const uint8_t relayPinA, const uint8_t relayPinB);

	/*!
	 * Controls ball valve based on the state provided
	 * @param state state to be changed to
	 */
	void control(Subsystem::BinaryState state);
};

#endif //CONTROL_NEW_BALLVALVE_H
