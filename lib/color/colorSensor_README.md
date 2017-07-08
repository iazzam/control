# Color Sensor

## Workings of the Sensor
This is for the control of the Balluff BFS 33M-GSS-F01-PU-02 Color Sensor, to be used to track the Pods movement.
Check following links to learn more about this sensor:
* https://docs.google.com/document/d/1spwh59uu49jK5YAjyDzP3ivckMVZAU12E6Pg1tBiL78/edit?usp=sharing
* https://drive.google.com/drive/u/0/folders/0B2mBhrOGlUfKdzcxWnJINmpjc00

For the second link, go under the Tube_Spec file, ctrl F "tape" to see the use of the sensor).

## Code Implementation
The sensor has three output ports, Out 1 - 3, which is used to describe the color said sensor detects. 
The values recorded for each Out range from 0 - 1023 but the code implemented reduces the range to 0 & 1 (for now).

The data sent to the dashboard is the color range value from 0 to 7.

**Expected JSON returned:**
```C++
{"time":1009,"sensor":"Color","data":[2]}
```
