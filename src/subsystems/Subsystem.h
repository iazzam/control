/*!
 * @author Deep Dhillon
 * @date July 26, 2017
 * @brief A Base class for all the sensors to make it easier to add more systems
 */

#ifndef CONTROL_NEW_SUBSYSTEM_H
#define CONTROL_NEW_SUBSYSTEM_H

#include <StandardCplusplus.h>
#include <vector>

class Subsystem{
public:
	enum class BinaryState{
		On,
		Off
	};

	/*!
	 * Single constructor creates a Subsystem
	 * @param constantApply is used to differentiate between systems that need
	 * 		  constant power and the ones who need only when they change state
	 */
	Subsystem(const bool constantApply=false);

	/*!
	 * Controls the state of the Subsystem based on a state given
	 * @param state of the system
	 */
	virtual void control(const Subsystem::BinaryState state);

	/*!
	 * Controls the State of the Subsystem based on a value given
	 * @param value is the value for that system
	 */
	virtual void control(const int value);

	virtual ~Subsystem() = default;

	/*!
	 * Converts a boolean to a state
	 * @param value value to be converted
	 * @return the state
	 */
	static BinaryState getState(uint8_t value);

private:
	const bool constantApply;
	int lastValue;
	Subsystem::BinaryState lastState;

protected:
	/*!
	 * This is used to figure out whether to change the value or keep it the same
	 * @param currentValue is the new value
	 * @return true or false
	 */
	bool shouldControl(const int currentValue);

	/*!
	 * This is used to figure out whether to change the state or keep it the same
	 * @param currentState is the new state
	 * @return true or false
	 */
	bool shouldControl(const Subsystem::BinaryState currentState);

	/*!
	 * Gives access to the last value of the system
	 * @return last value
	 */
	int getLastValue();
};

#endif //CONTROL_NEW_SUBSYSTEM_H
