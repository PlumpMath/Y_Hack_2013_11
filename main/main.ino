//includes
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "UnoJoy.h"
#include "Controller.h"

void setup() {
    Controller c = new Controller();

    c.setup();

    //debug
    Serial.begin(9600);
}

void loop() {
    Controller c = new Controller();

    c.push();
}
