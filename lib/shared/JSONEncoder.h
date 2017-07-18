/*!
 * @author Deep Dhillon
 * @date 2017-05-25
 * @brief This class handles sensor data and provides methods to manipulate data
 */

#ifndef SRC_IMUDATA_H_
#define SRC_IMUDATA_H_

#include "ArduinoJson.h"
#include <Arduino.h>

class JSONEncoder {
public:
    /*!
     * Creates a JSON String from the Sensor data provided and adds support for heartbeat
     * @param name name of the sensor from which data is obtained
     * @param sensorData an array of data points
     * @param numData  number of data points in the array
     * @param counter adds another key for heartbeat
     * @return the JSON String
     */
    String encodeSensor(const String &name, const float *sensorData,
                        const int numData, const int counter=-1) const ;


    /*!
    * Creates a JSON String from the command provided
    * @param command_name is the name of command
    * @return the JSON String
    */
    String encodeCommand(const String &commandName) const;

    /*!
     * Creates a JSON String from the status provided
     * @param statusName is the name of the status
     * @return the JSON String
     */
    String encodeStatus(const String &statusName) const;

    /*!
     * Creates a JSON String from the message provided
     * @param message is the name of the message
     * @return the JSON String
     */
    String encodeMessage(const String &message) const;
};

#endif
