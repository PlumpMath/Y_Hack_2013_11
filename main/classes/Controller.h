#ifndef Adafruit_MCP23017
    #include <../vendor/Adafruit_MCP23017.h>
#endif

#ifndef dataForController_t
    #include <../vendor/UnoJoy.h>
#endif

class Controller
{
    Controller();

    void setup();
    void setupPins();
    void prepare(int, bool);
    void read(int, bool);
    void push();
    dataForController_t get();

    int buttons[8];
    dataForController_t bin;

    Adafruit_MCP23017 mcp;
};
