#include <Arduino.h>
#include "Control.h"

Control c{20, 15000, 115200};

void setup(){
    c.setup();
}

void loop(){
    c.loop();
}
