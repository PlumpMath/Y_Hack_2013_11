#include "Controller.h"

void Controller::setup() {
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
    if (ada == false) {
        pinMode(pin, INPUT);
        digitalWrite(pin, HIGH);
    } else {
        mcp.pinMode(pin, INPUT);
        mcp.digitalWrite(pin, HIGH);
    }
}

int Controller::read(int pin, bool ada) {
    for (int i = 0; i < 8; i++) {
        if (ada == false) {
            return analogRead(pin);
        } else {
            return !mcp.digitalRead(pin);
        }
    }
}

void Controller::push() {
    setControllerData(get());
}

dataForController_t Controller::get() {
    dataForController_t data = getBlankDataForController();

    data.triangleOn = read(0, true);
    data.circleOn = read(1, true);
    data.squareOn = read(2, true);
    data.crossOn = read(3, true);
    //data.dpadUpOn = read(, true);
    data.dpadDownOn = read(4, true);
    data.dpadLeftOn = read(5, true);
    data.dpadDownOn = read(6, true);
    data.l1On = read(7, true);
    //data.r1On = read(, true);
    //data.selectOn = read(, true);
    //data.startOn = read(, true);
    //data.homeOn = read(, true);

    data.leftStickX = read(A3, false);
    data.leftStickY = read(A2, false);

    return data;
}
