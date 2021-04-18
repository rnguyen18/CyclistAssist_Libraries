#include "Arduino.h"
#include "SpeedometerController.h"

SpeedometerController::SpeedometerController(int sensorPin) {
	pinMode(sensorPin, INPUT_PULLUP);
	Serial.write("SpeedometerController Initialized\n");
	on = false;
	rotations = 0;
	time = millis();
}

void SpeedometerController::Update() {
	int returnVal = 0;
	int sensorVal = digitalRead(sensorPin);
	if (!sensorVal && sensorVal != on) {
		on = sensorVal;
		rotations = rotations + 1;
	}
	if (millis()-time > SEND_TIMING) {
		returnVal = rotations;
		rotations = 0;
	}
	return returnVal;
}