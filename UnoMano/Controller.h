
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Arduino.h"
#include "Adafruit_MCP23017.h"
#include "UnoJoy.h"
#include <Wire.h>
class Controller
{
	public:
		Controller();

		void setup();
		void setupPins();
		void prepare(int, bool);
		int read(int, bool);
		void push();
		dataForController_t get();

		int buttons[8];
		dataForController_t bin;

		Adafruit_MCP23017 mcp;
};
#endif
