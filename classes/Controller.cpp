class Controller
{
    Controller();

    void setupPins();
    void prepare(int, bool);
    void read(int, bool);
    void push();

    int buttons[8];
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
    if (ada == false) {
        pinMode(pin, INPUT);
        digitalWrite(pin, HIGH);
    } else {
        mcp.pinMode(pin, INPUT);
        mcp.digitalWrite(pin, HIGH);
    }
}

void Controller::read(int pin, bool ada) {
    for (int i = 0; i < 8; i++) {
        if (ada == false) {
            analogRead(pin);
        } else {
            !mcp.digitalRead(pin);
        }
    }
}

void Controller::push() {
    return bin;
}

dataForController_t get() {
    dataForController_t data = getBlankDataForController();
    int controller_buttons[8] = {
        "triangleOn",
        "circleOn",
        "squareOn",
        "crossOn",
        "dpadDownOn",
        "dpadLeftOn",
        "dpadRightOn",
        "lqOn"
    };

    for (int i = 0; i < 8; i++) {
        data[controller_buttons[i]] = read(i, true);
    }

    data.leftStickX = read(A0, false);
    data.leftStickY = read(A1, false);

    return data;
}
