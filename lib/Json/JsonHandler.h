/*!
 * @author Deep Dhillon
 * @date 2017-05-25
 * @brief This class handles the data to be sent and provides methods to encode it
 */

#ifndef SRC_IMUDATA_H_
#define SRC_IMUDATA_H_

#include <StandardCplusplus.h>
#include <ArduinoJson.h>
#include <WString.h>
#include <utility.h>

namespace wlp{
    class JsonHandler {
    public:
        /*!
		 * Creates a JSON String from the Sensor data provided and adds support for heartbeat
		 * @param name name of the sensor from which data is obtained
		 * @param sensorData an array of data points
		 * @param numData  number of data points in the array
		 * @param counter adds another key for heartbeat
		 * @return the JSON String
		 */
        const String encodeSensor(const String name, const float *sensorData,
                            const int numData, const int counter=-1) const ;


        /*!
		* Creates a JSON String from the command provided
		* @param command_name is the name of command
		* @return the JSON String
		*/
        const String encodeCommand(const String commandName) const;


        /*!
		 * Creates a JSON String from the message provided
		 * @param message is the name of the message
		 * @return the JSON String
		 */
        const String encodeMessage(const String message) const;

        /*!
		 * Decodes the command received in JSON format
		 * @param command command to decode
		 * @return a pair that included the name and value of the command
		 */
        const std::pair<String, int> decodeCommand(String command);
    };

    extern JsonHandler json;
}


#endif
