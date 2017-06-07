#include <Arduino.h>
#include "Control.h"
Control c;
void setup(){
    Serial.begin(9600);
}

void loop(){
    c.loop();
}
