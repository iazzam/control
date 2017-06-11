#include <Arduino.h>
#include "Control.h"

Control c{50, 15000, 115200};
void setup(){
    c.setup();

}

void loop(){
    c.loop();
    //Serial.println(45);
}




