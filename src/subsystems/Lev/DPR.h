/*!
 * @authors Deep Dhillon Christopher
 * @date June 10, 2017
 * @brief This library is used to control levitation's DPR system
 */

#ifndef CONTROL_NEW_DPR_H
#define CONTROL_NEW_DPR_H

#include <stdint.h>
#include <subsystems/Subsystem.h>

class DPR: public Subsystem{
	const uint8_t relayPin;

public:
	/*!
	 * Single constructor creates DPR
	 * @param relayPin the relay pin DPR is attached to
	 */
	DPR(const uint8_t relayPin);

	/*!
	 * Controls DPR based on the state provided
	 * @param state state to be changed to
	 */
	void control(Subsystem::BinaryState state);
};

#endif //CONTROL_NEW_DPR_H
