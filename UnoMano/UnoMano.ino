//includes
#include <Wire.h>

#include "UnoJoy.h"
#include "Adafruit_MCP23017.h"

//////////////////////////////////////////////////////////////////////////////////////////
/**
 * MCP
 *
 * @see Adafruit_MCP23017.h
 */
Adafruit_MCP23017 mcp;

// {{{ preparePin

/**
 * Prepare a pin
 *
 * @param	int 	pin number
 * @param	bool	true if MCP
 */
void preparePin(int pin, bool ada) {
    if (ada == false) {
        pinMode(pin, INPUT);
        digitalWrite(pin, HIGH);
    } else {
        mcp.pinMode(pin, INPUT);
        mcp.digitalWrite(pin, HIGH);
    }
}

// }}}
// {{{ setupPins

/**
 * Prepare all pins
 *
 * 0 - 7 MCP
 * A0 & A1 left axis
 */
void setupPins() {
    //buttons on Adafruit
    for (int i = 0; i < 8; i++) {
        preparePin(i, true);
    }

    //axis
    preparePin(A0, false);
    preparePin(A1, false);
}

// }}}
// {{{ readPin

/**
 * Read a pin
 *
 * @param	int 	pin number
 * @param   bool    true if MCP
 * @return  int     value of pin
 */
int readPin(int pin, bool ada) {
    for (int i = 0; i < 8; i++) {
        if (ada == false) {
            return analogRead(pin);
        } else {
            return !mcp.digitalRead(pin);
        }
    }
}

// }}}
// {{{ getControllerData

/**
 * Read all pins
 *
 * @return	dataForController_t		all pin values
 */
dataForController_t getControllerData() {
    dataForController_t data = getBlankDataForController();

    data.triangleOn = readPin(0, true);
    data.circleOn = readPin(1, true);
    data.squareOn = readPin(2, true);
    data.crossOn = readPin(3, true);
    //data.dpadUpOn = readPin(, true);
    data.dpadDownOn = readPin(4, true);
    data.dpadLeftOn = readPin(5, true);
    data.dpadDownOn = readPin(6, true);
    data.l1On = readPin(7, true);
    //data.r1On = readPin(, true);
    //data.selectOn = readPin(, true);
    //data.startOn = readPin(, true);
    //data.homeOn = readPin(, true);

    data.leftStickX = readPin(A3, false);
    data.leftStickY = readPin(A2, false);

    return data;
}

// }}}
//////////////////////////////////////////////////////////////////////////////////////////

void setup() {
    setupPins();
    setupUnoJoy();

    //debug
    Serial.begin(9600);
}

void loop() {
	setControllerData(getControllerData());
}
