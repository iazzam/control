#include "TMP36.h"


TMP36::TMP36(const String name, const uint8_t freq, const uint8_t pin)
        : Sensor{name, freq, 1}, pin{pin}{}

int TMP36::getRawTemp() {
    return analogRead(pin);
}

float TMP36::read(){
    //getting the voltage reading from the temperature sensor
    int reading = getRawTemp();

    // converting that reading to voltage
    float voltage = reading * 5.0;
    voltage /= MAX_ANALOG;

    float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset

    add(temperatureC);

    return temperatureC;
}
