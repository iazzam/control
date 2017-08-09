/*!
 * @author Deep Dhillon
 * @date July 26, 2017
 * @brief This represents each single command and can be used to add more
 * 		  commands
 */

#ifndef CONTROL_NEW_COMMAND_H
#define CONTROL_NEW_COMMAND_H

#include <WString.h>
#include <utility.h>

class Command{
	const String name;
	static bool podStart;

	// variables to manipulate in State class
	int &state;

	/*!
	 * Stop command is used to determine a lot of things like if to process
	 * a command or not. So, this handles that command separately
	 * @param command is the command received
	 */
	void handleStartAndStop(const std::pair<String, uint8_t> command);
public:
	/*!
	 * Single constructor to create Command
	 * @param name name of the command
	 * @param state state to manipulate
	 */
	Command(const String name, int &state);

	/*!
	 * When a command is received, this is called to process is the command
	 * @param decoder command that is parsed
	 * @return true or false based on if command is processed
	 */
	bool notiy(const std::pair<String, int> command);

	/*!
	 * Sets the initial on state for the pod so that commands know if the
	 * pod is on or off
	 * @param stop is the state of the pod (start or stop)
	 */
	static void setOnState(bool stop);
};

#endif //CONTROL_NEW_COMMAND_H
