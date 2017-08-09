/*!
 * @author Deep Dhillon
 * @date July 15, 2017
 * @brief This library is used to control Drive Train
 */

#ifndef CONTROL_NEW_DRIVETRAIN_H
#define CONTROL_NEW_DRIVETRAIN_H

#include <stdint.h>
#include <subsystems/Subsystem.h>

class DriveTrain : public Subsystem{
	const uint8_t relayPinDrive;
	const uint8_t analogPin;
	const uint8_t relayPinDrop;
	bool dropped;
public:
	/*!
	 * Single constructor creates DriveTrain
	 * @param relayPinDrive the relay pin Drive motor's one pin is attached to
	 * @param analogPin the pin used to control the speed of the drive
	 * @param relayPinDrop the relay pin Drop motor is attached to
	 */
	DriveTrain(const uint8_t relayPinDrive, const uint8_t analogPin,
	           const uint8_t relayPinDrop);

	/*!
	 * Controls the drive train based on the speed provided. If speed is
	 * negative, drive is reversed
	 * @param speed speed of the drive train
	 */
	void control(const int speed);

	/*!
	 * Handles the drop of the drive train
	 * @param state state of the drop
	 */
	void drop(const Subsystem::BinaryState state);
};

#endif //CONTROL_NEW_DRIVETRAIN_H
