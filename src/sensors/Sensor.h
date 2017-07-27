/*!
 * @author Deep Dhillon
 * @date July 11, 2017
 * @brief A Base class for all the sensors to make it easier to add more sensors
 */

#ifndef CONTROL_SENSOR_H
#define CONTROL_SENSOR_H

#include <WSerial.h>
#include <WSerial.h>

class Sensor{
    String name;
    const int rate;
    int numInputs;

    const bool heartBeat;
    int check;
    int printCounter;
    long prevTime;
    float *array = nullptr;
    int arrayCounter;
    String JSONString;

protected:
    void setCheck(const int check);

    // constants for sensor
    const float MIN_ANALOG = 0.0;
    const float MAX_ANALOG = 1023.0;

public:

    /*!
     * Single constructor creates a Sensor
     * @param name name of the sensor
     * @param rate rate at which this sensor will function
     * @param numInputs is the number of sensor values
     */
    Sensor (const String name, const int rate, const int numInputs, const bool heartBeat=false);

    /*!
     * Destructor deletes the array used to store sensor inputs
     */
    virtual ~Sensor();

    /*!
     * Reads data from the sensor
     * @return the data received from the sensor
     */
    virtual float read() = 0;

    /*!
     * Checks if the sensor read and print rate is being followed
     * @return true or false
     */
    bool rateCheck();

    /*!
     * Adds value provided to the array
     * @param val is the value to be store
     */
    void add(const float val);

    /*!
     * Creates a JSON String based on the array of inputs
     * @param check is a value used for heartbeat
     * @return the JSON String
     */
    String &getJSON(const int check=-1);

    /*!
     * Returns the value stored at given address
     * @param index of the array
     * @return value at the index
     */
    float get(const int index);

    /*!
     * Tells the name of the sensor
     * @return the name of the sensor
     */
    String &getName();

	/*!
	 * Gives acces to the functioning rate of the sensor
	 * @return the rate
	 */
    const int getRate();

    friend wlp::WSerial &operator <<(wlp::WSerial &serial, Sensor &sensor);
};

/*!
 * Prints data to the Serial
 * @param serial is the serial
 * @param sensor is the sensor being used
 * @return the serial
 */
wlp::WSerial &operator <<(wlp::WSerial &serial, Sensor &sensor);

#endif //CONTROL_SENSOR_H
