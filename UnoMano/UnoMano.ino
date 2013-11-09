//includes
#include <Wire.h>

#include "Controller.h"

void setup() {
    Controller c;

    c.setup();

    //debug
    Serial.begin(9600);
}

void loop() {
    Controller c;

    c.push();
}
