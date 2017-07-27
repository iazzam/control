/*!
 * @author Deep Dhillon
 * @date July 26, 2017
 * @brief Commands Listener is used to listen to command and to parse them
 */

#ifndef CONTROL_NEW_COMMANDLISTENER_H
#define CONTROL_NEW_COMMANDLISTENER_H

#include <StandardCplusplus.h>
#include <vector>
#include "Command.h"

class State;
class String;

class CommandListener{
	// Fields for Serial Commands reading
	const uint8_t maxChar = 30;
	char *receivedChars;
	bool newData = false;
	bool reading = false;
	uint8_t charIndex = 0;
	char startMarker = '{';
	char endMarker = '}';

	// state to be used
	State &state;

	// vector for adding commands
	std::vector<Command*> commands;

	/*!
	 * Reads commands from the serial one character at a time until it finishes
	 * a word
	 */
	void readCommand();

	/*!
	 * Given a JSON string, this parses the command and notifies all the
	 * command objects to update based on the command
	 * @param command command provided
	 */
	void parseCommand(const String command);

	/*!
	 * Commands are added to a list of commands
	 * @param state State object that will be used
	 */
	void addCommands(State &state);

	/*!
	 *
	 */
	void checkStatesValidity();
public:
	/*!
	 * Single Constructor creates a Command listener
	 * @param state State object that will be used
	 */
	CommandListener(State &state);

	~CommandListener();

	/*!
	 * Listens for commands and if a command is received, calls other methods
	 * to handle them
	 */
	void listen();
};

#endif //CONTROL_NEW_COMMANDLISTENER_H
