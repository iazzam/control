#include <Arduino.h>
#include "Control.h"

Control c{50, 14796, 115200};

void setup(){
    c.setup();
}

void loop(){
    c.loop();
}
