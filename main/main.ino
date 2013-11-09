//includes
#include <Wire.h>
#include "../vendor/Adafruit_MCP23017.h"
#include "../vendor/UnoJoy.h"

#include "../classes/Controller.cpp"

class Controller
{
    public:
        Controller();
        void setupPins();
        void prepare(int);

    private:
        int buttons[7];
        dataForController_t bin;

        Adafruit_MCP23017 mcp;
}

Controller::Controller() {
    setupPins();
    setupUnoJoy();
}

void Controller::setupPins() {
    //buttons on Adafruit
    for (int i = 0; i < 8; i++) {
        prepare(i, true);
    }

    //axis
    prepare(A0, false);
    prepare(A1, false);
}

void Controller::prepare(int pin, bool ada) {
    if (ada) {
        pinMode(pin, INPUT);
        digitalWrite(pin, HIGH);
    } else {
        mcp.pinMode(pin, INPUT);
        mcp.digitalWrite(pin, HIGH);
    }
}

Adafruit_MCP23017 mcp;
dataForController_t controllerData;

//controller
int TRIANGLE      = 0;
int CIRCLE        = 1;
int SQUARE        = 2;
int CROSS         = 3;
int DPAD_UP       = null;
int DPAD_DOWN     = 5;
int DPAD_LEFT     = 6;
int DPAD_RIGHT    = 7;
int L_ONE         = 4;
int R_ONE         = null;
int SELECT        = null;
int START         = null;
int HOME          = null;

void setup() {
    setupPins();
    setupUnoJoy();

    //debug
    Serial.begin(9600);
}

void setupPins() {
    mcp.pinMode(TRIANGLE, INPUT);
    mcp.pinMode(CIRCLE, INPUT);
    mcp.pinMode(SQUARE, INPUT);
    mcp.pinMode(CROSS, INPUT);
    mcp.pinMode(DPAD_DOWN, INPUT);
    mcp.pinMode(DPAD_LEFT, INPUT);
    mcp.pinMode(DPAD_RIGHT, INPUT);
    mcp.pinMode(L_ONE, INPUT);
}

void loop() {
    controllerData = getControllerData();
    setControllerData(controllerData);
}

dataForController_t getControllerData() {
    dataForController_t controllerData = getBlankDataForController();

    controllerData.triangleOn = !mcp.digitalRead(TRIANGLE);
    controllerData.circleOn = !mcp.digitalRead(CIRCLE);
    controllerData.squareOn = !mcp.digitalRead(SQUARE);
    controllerData.crossOn = !mcp.digitalRead(CROSS);

    controllerData.dpadDownOn = !mcp.digitalRead(DPAD_DOWN);
    controllerData.dpadLeftOn = !mcp.digitalRead(DPAD_LEFT);
    controllerData.dpadRightOn = !mcp.digitalRead(DPAD_RIGHT);

    controllerData.l1On = !mcp.digitalRead(L_ONE);

    controllerData.leftStickX = analogRead(A0) >> 2;
    controllerData.leftStickY = analogRead(A1) >> 2;

    Serial.println(controllerData);
    return controllerData;
}