#include "Arduino.h"
#include "SpeedometerController.h"

SpeedometerController::SpeedometerController(int sensorPin) {
	pinMode(sensorPin, INPUT_PULLUP);
	sensor_pin = sensorPin;
	on = 1;
	time = millis();
	start_revolution = 0;
}

int SpeedometerController::Update() {
	int returnVal = -1;
	int sensorVal = digitalRead(sensor_pin);
	
	if (sensorVal == 0 && sensorVal != on) {
		on = sensorVal;
		if (start_revolution != 0) {
			period = millis() - start_revolution;
		}
		start_revolution = millis();
	} else if (sensorVal == 1) {
		on = sensorVal;
	}
	
	
	if (millis()-time >= SEND_TIMING) {
		returnVal = period;
		time = millis();
		period = 0;
	}
	return returnVal;
}