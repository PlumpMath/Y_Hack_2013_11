//includes
#include <Wire.h>
#include "../vendor/Adafruit_MCP23017.h"
#include "../vendor/UnoJoy.h"

#include "../classes/Controller.cpp"

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
