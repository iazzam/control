#include "TMP36.h"


TMP36::TMP36(const String name, const uint8_t io_pin) : name{name}, io_pin{io_pin}{}


void TMP36::serialPrint() {
    float *temp = new float[1];
    temp[0] = getTemp();

    Serial.println(handler.getJSONString(name, temp, 1));
    delete [] temp;
}


float TMP36::getTemp() const{
    int8_t sensorInput = analogRead(io_pin);            //read the analog sensor and store it
    float temp = (double)sensorInput / 1024;            //find percentage of input reading
    temp = temp * 5;                                    //multiply by 5V to get voltage
    temp = temp - 0.5;                                  //Subtract the offset
    temp = temp * 100;                                  //Convert to degrees

    return temp;
}
