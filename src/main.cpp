#include <Arduino.h>
#include "Control.h"
Control c;
void setup(){
    Serial.begin(115200);
}

void loop(){
    c.loop();
}
