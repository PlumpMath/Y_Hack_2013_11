//includes
#include <Wire.h>

void setup() {
        Wire.begin();
	Serial.begin(9600);
}

void loop() {
	//address port B
	Wire.beginTransmission(0x20);
	Wire.write(0x13);
	Wire.endTransmission();
	
	//request one byte from 0x20
	Wire.requestFrom(0x20, 1);

	int inputs = Wire.read();

	Serial.println(inputs);
}
