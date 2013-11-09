//includes
#include <Wire.h>
#include <vendor/Adafruit_MCP23017.h>
#include <vendor/UnoJoy.h>

#include <classes/Controller.h>

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
