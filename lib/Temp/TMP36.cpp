#include "TMP36.h"


TMP36::TMP36(const String name, const uint8_t io_pin) : name{name}, io_pin{io_pin}{}


void TMP36::serialPrint(WSerial &serial) {
    float *temp = new float[1];
    temp[0] = getTemp();

    serial << handler.getJSONString(name, temp, 1) << endl;
    delete [] temp;
}


float TMP36::getTemp() const{
    float temp = (5.0 * analogRead(io_pin) * 100.0) / 1024;
    return temp;
}
