/*!
 * @author Sid Mishra
 * @date July 08, 2017
 * @brief This library is used to control EC Brakes
 */

#ifndef CONTROL_NEW_ECBRAKES_H
#define CONTROL_NEW_ECBRAKES_H

#include <subsystems/Subsystem.h>

class ECBrakes : public Subsystem{
	const uint8_t relayPin;
public:
	/*!
	 * Single constructor creates ECBrakes
	 * @param relayPin the relay pin EC Brakes are attached to
	 */
	ECBrakes(const uint8_t relayPin);

	/*!
	 * Controls EC Brakes based on the state provided
	 * @param state state to be changed to
	 */
	void control(Subsystem::State state);
};

#endif //CONTROL_NEW_ECBRAKES_H
