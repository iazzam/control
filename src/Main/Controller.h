/*!
 * @author Deep Dhillon
 * @date 2017-06-25
 * @brief This class is used to control the pod and provide for an interface to make everything work
 */

#ifndef CONTROL_POD_CONTROLLER_H
#define CONTROL_POD_CONTROLLER_H

#include <HardwareSerial.h>
#include <ArduinoJson.h>
#include <Configurations/State.h>
#include <Configurations/Config.h>
#include <ColorSensor.h>
#include <Subsystems/Lev/BallValve.h>
#include <WSerial.h>

class Controller {
    // Serial related field
    const unsigned long band_rate;

    // Fields for Serial Commands
    const int max_char = 30; /*!< Maximum length of commands allowed */
    char *received_chars;
    bool new_data = false;
    bool reading = false;
    int char_index = 0;
    char start_marker = '{'; /*!< Will only read commands that start with { */
    char end_marker = '}'; /*!< Will only read commands that end with } */

    // Field for State object
    State s;

    // sensors objects
    ColorSensor colorSensor;
    BallValve ballValve;

    // serial objects
    WSerial serial;

    /*!
     * Reading listener to keep listening for commands that are being passed
     * through Serial
     */
    void readCommand();

    /*!
     * Parses the command read from the Serial and signals for the change
     * of the state based on that
     * @param json_string a JSON String representing the command
     */
    void parseCommand(String command);

    /*!
     * Handles the case when there is emergency and an action has to be taken. This
     * has the top most priority and is executed as quickly as possible
     */
    void emergencyProtocol();

    /*!
     * Handles all the manual controls for the pod. This allows us to
     * manually adjust various features of the pod from the control panel
     */
    void handleManual();

    /*!
     * Allows us to run a script when we need to test something. The code will keep executing
     * what is defined in this function
     */
    void handleScript();

    /*!
     * Handles all the manual controls for the pod. This allows us to
     * manually adjust various features of the pod from the control panel
     */
    void handleAutonomous();
public:
    /*!
     * The only constructor for this class. It uses bit rate to determine the
     * data flow rate of Serial connection
     * @param band_rate bit rate of Serial connection
     */
    Controller(const unsigned long band_rate);

    /*!
     * Destructor deletes all the subsystems on the pod when Control
     * goes off the scope
     */
    ~Controller();

    /*!
     * This method holds the code that will be run at the beginning. Is used
     * for initializing various pod parts
     */
    void setup();

    /*!
     * This method is in charge of handling and parsing commands received from
     * Serial. It calls other methods to do it's tasks
     */
    void handleCommands();

    /*!
     * This method acts as a loop that controls the working of the pod. It handles
     * various function modes like: Autonomous, Manual and Script
     */
    void control();
};


#endif //CONTROL_POD_CONTROLLER_H
