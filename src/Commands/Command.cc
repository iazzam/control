#include <WSerial.h>
#include <JsonHandler.h>
#include "Command.h"

using namespace wlp;

bool Command::podStart = false;

Command::Command(const String name, uint8_t &state): name{name}, state{state}{}

bool Command::notiy(const std::pair<String, uint8_t> command){
	// handle start and stop commands differently
	if (command.first == name && name == "stop"){
		handleStartAndStop(command);
		return true;
	}


	if (command.first == name){
		// do not process any command is pod has not been started
		if (!podStart){
			serial << json.encodeMessage("start the pod first") << endl;
			return true;
		}

		if(command.second != state){
			state = command.second;

			if(command.first != "check")
				serial << json.encodeMessage("command changed state") << endl;
		} else
			serial << json.encodeMessage("command had no effect") << endl;
		return true;
	}

	return false;
}

void Command::handleStartAndStop(const std::pair<String, uint8_t> command){
	if (command.second == 0){
		// turn stop off aka turn start on

		if (command.second == state){
			serial << json.encodeMessage("pod has already started") << endl;
		} else{
			podStart = true;
			state = command.second;
			serial << json.encodeMessage("pod started") << endl;
		}

	} else if (command.second == 1){
		// turn stop on aka turn start off

		if (command.second == state){
			serial << json.encodeMessage("pod has already stopped") << endl;
		} else{
			podStart = false;
			state = command.second;
			serial << json.encodeMessage("pod stopped") << endl;
		}

	}
}

static void Command::setOnState(bool stop){ podStart = !stop; }
