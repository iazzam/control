# Lev sensors

This subsystem contains the DPR pressure sensor and the photoelectric distance sensor.

The Lev class must be instantiated with the pin numbers of the required analog pins.

Example data returned:
```C++
// Min voltage
{"time":0,"sensor":"distance","data":[0]}

// Max voltage
{"time":1,"sensor":"DPR","data":[1023]}
```

The `get_distance()` and `get_DPR()` functions return the 0-5V voltage scaled as an integer between 0 and 1023 inclusive.

The `print` functions print their respective values as JSON to serial.
