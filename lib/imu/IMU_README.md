# IMU Sensors

This controls all the IMU sensors on the pod. Each sensor contains three types of sub sensors.
These sub sensors are `GyroScope`, `Accelerometer` and `Magnetometer`. The data gathered from each sensor is in JSON format.

Example JSON data returned:

```cpp
// This contains data from Gyroscope
{"time":1009,"sensor":"gyro","data":[-1.54875,12.19750,11.36625]}

// This contains data from only Accelerometer
{"time":1009,"sensor":"accelerometer","data":[-0.02300,-0.02300,-0.02300]}

// This contains data from only Magnetometer
{"time":1009,"sensor": "magnetometer", "data":[0.41986,0.41986,0.41986]}
```

More about data recieved is mentioned later on.

## How to Use

This set of sensors are controlled by `IMUPool` class. An Object must be created of this class to gather data from all the sensor. To create an object, you have to pass in a parameter to specify how many imu sensors are on the pod

```cpp
IMUPool imus(2);            // create 2 imu sensors
```

Before recording any sensor values, we have to check if all the imu sensors are working. To do this, call `sensorsWorking` method and it will return true to signal the working of all the sensors and false even if one sensor is not working

```cpp
if (imus.sensorsWorking()){}    // success
else{}                          // failure
```

### Overview of functions to gather data
Each component of IMU sensor returns x, y and z values. Since the data is formatted in JSON format, the data received by any function call includes x, y and z for that particular sensor. JSON format also includes a time in milliseconds. This time is the time elapsed since the Arduino has started working.

Data in JSON format cannot be received as a string but rather you can print it directly to the Serial. To do this you can make
a call `serialPrint`.

```cpp
imus.serialPrint(0, GYRO);        // data for Gyroscope from sensor 0
imus.serialPrint(1, ACCEL);    // data for Accelerometer from sensor 1
imus.serialPrint(1, MAG);         // data for Magnetometer from sensor 1
```

If for some reason read fails for any component of any sensor, the output for that component will be `-99999.00000` for x, y and z axis.
Since the value of any sensor component will never be `-99999.00000`, we can detect failure and take actions accordingly.

```cpp
// In this data, Gyroscope read failed
{"time":1039,"sensor":"gyroscope":[-99999.00000,-99999.00000,-99999.00000]}
```

Now that above functions return values for Serial communications, we may need values in float format so that our pod can utilize them.
In order to do that, there are following functions:
 
```cpp
imus.getX(0, GYRO);                 // x data for Gyroscope and from sensor 0
imus.getY(1, ACCEL);                // y data for Accelerometer and from sensor 1
imus.getZ(1, MAG);                  // z data for Magnetometer and from sensor 1
```

To get the number of sensors in the subsystem, call the method `getTotal`. 

```C++
imus.getTotal();                    // will return 2 based on our declaration of the object above
```

## Documentation of IMU class used by IMUPool class

`IMU` class is used by IMUPool to make everything work. A client can choose to use `IMU` class if he/she wishes to do so. Keep in mind this class only supports one IMU sensor and does not return data in JSON format. But, this class can be modified to change the functionality of each components for IMU sensor. These changes will also show up on `IMUPool`.

Create an object of this class.

```cpp
IMU sensor;
```

If you are not satisfied by how `Gyroscope` or `Accelerometer` or `Magnetometer` component works and outputs data, you can change  the settings of each component using `setup` methods. These methods have default values so you do not have to specify every parameter.

```C++
// setupGyro() specifies the settings for the gyroscope.
// * scale sets the full-scale range of the gyroscope. scale can be set to either 245, 500, or 2000
// * sampleRatesets the output data rate (ODR) of the gyro
//   sampleRate can be set between 1-6
// 	 1 = 14.9    4 = 238
//   2 = 59.5    5 = 476
//   3 = 119     6 = 952
// * flipX, flipY, and flipZ are booleans that can automatically switch the positive/negative
//   orientation of the three gyro axes.
void setupGyro(int scale=245, int sampleRate=3, bool flipX=false, bool flipY=false, bool flipZ=false);

// setupAccel() specifies the settings for the accelerometer.
// * scale sets the full-scale range of accelerometer. The scale can be 2, 4, 8 or 16
// * sampleRate sets the output data rate of the accelerometer. If Gyroscope is running,
//   the sample rate is same as gyroscope. Same rate can be be 1-6:
//   1 = 10 Hz    4 = 238 Hz
//   2 = 50 Hz    5 = 476 Hz
//   3 = 119 Hz   6 = 952 Hz
void setupAccel(int scale=8, int sampleRate=1);

// setupMag() specifies the settings for the magnetometer.
// * scale sets the full-scale range of the magnetometer. Mag scale can be 4, 8, 12, or 16
// * sampleRate sets the output data rate (ODR) of the magnetometer.
//   mag data rate can be 0-7:
//   0 = 0.625 Hz  4 = 10 Hz
//   1 = 1.25 Hz   5 = 20 Hz
//   2 = 2.5 Hz    6 = 40 Hz
//   3 = 5 Hz      7 = 80 Hz
// * tempComp enables or disables temperature compensation of the magnetometer.
// * operatingMode sets the operating mode of the magnetometer. operatingMode can be 0-2:
//   0 = continuous conversion
//   1 = single-conversion
//   2 = power down
void setupMag(int scale=12, int sampleRate=5, bool tempComp=false, int operatingMode=0);
```

You can get data from each data component of the sensor by using `get` methods. Before getting these x, y and z values, you have to read the sensor.
To read the sensor, use the `read` method. This method returns true if the read was successful and false if it was unsuccessful.

```C++
read(GYRO);       // read GYRO
read(ACCEL);      // reada ACCEL
read(MAG);        // read MAG
```

After the read is successful, you can go ahead and get data from that component. Data acquired from each component is of type `float` and it is precise to `5 decimal points`.

```C++
// X values
getX(GYRO);       // GYRO X Value
getX(ACCEL);      // ACCEL X Value
getX(MAG);        // MAG X Value

// Y values
getY(GYRO);       // GYRO Y Value
getY(ACCEL);      // ACCEL Y Value
getY(MAG);        // MAG Y Value

// Z values
getZ(GYRO);       // GYRO Z Value
getZ(ACCEL);      // ACCEL Z Value
getZ(MAG);        // MAG Z Value
```