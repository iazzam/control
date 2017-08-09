#include <stdint.h>
#include <WString.h>
#include <WSerial.h>
#include <JsonHandler.h>
#include <Watchdog/State.h>
#include "CommandListener.h"

using namespace wlp;

CommandListener::CommandListener(State &state) : state(state){
	addCommands(state);
	receivedChars = new char[maxChar];
}

void CommandListener::addCommands(State &state){
	// set the pod state for every command
	Command::setOnState((bool) state.stop);

	commands.push_back(new Command("mode", state.mode));
	commands.push_back(new Command("rest", state.restart));
	commands.push_back(new Command("emg", state.emergency));
	commands.push_back(new Command("stop", state.stop));
	commands.push_back(new Command("check", state.check));

	commands.push_back(new Command("brk", state.brakes));
	commands.push_back(new Command("spdmag", state.magSpeed));
	commands.push_back(new Command("spddrive", state.driveSpeed));
	commands.push_back(new Command("ewd", state.drop));
	commands.push_back(new Command("dpr", state.dpr));
	commands.push_back(new Command("bv", state.ballValve));
}

CommandListener::~CommandListener(){
	int size = commands.size();

	for(int i = 0; i < size; ++i)
		delete commands[i];

	delete [] receivedChars;
}

void CommandListener::readCommand(){
	char curr_char;

	while (wlp::serial.available() > 0 && !newData) {
		curr_char = wlp::serial.readChar();

		if (reading) {
			if (curr_char != endMarker) {
				receivedChars[charIndex] = curr_char;
				++charIndex;

				// in case of overflow
				if (charIndex >= maxChar)
					charIndex = maxChar - 1;
			} else {
				receivedChars[charIndex] = curr_char;
				++charIndex;
				receivedChars[charIndex] = '\0'; // terminate the string

				reading = false;
				charIndex = 0;
				newData = true;
			}
		} else if (curr_char == startMarker) {
			receivedChars[charIndex] = curr_char;
			++charIndex;
			reading = true;
		}
	}
}

void CommandListener::parseCommand(const String command){
	//serial << json.encodeCommand(command) << endl;

	std::pair<String, int> cmd = json.decodeCommand(command);

	int size = commands.size();

	bool commandProcessed;

	for(int i = 0; i < size; ++i){
		commandProcessed = commands[i]->notiy(cmd);

		if (commandProcessed){
			checkStatesValidity();
			break;
		}
	}
}

void CommandListener::listen(){
	// read command if available
	readCommand();

	// parse the command and set flags
	if (newData){
		parseCommand(receivedChars);
		newData = false;
	}
}

void CommandListener::checkStatesValidity(){

}
