#include "Arduino.h"
#ifndef Adafruit_MCP23017
    #include "Adafruit_MCP23017.h"
#endif

#ifndef dataForController_t
    #include "UnoJoy.h"
#endif
#ifndef Controller_h
#define Controller_h

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
