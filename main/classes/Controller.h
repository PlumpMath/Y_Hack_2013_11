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

    Adafruit_MCP23017 mcp = new Adafruit_MCP23017();
};
