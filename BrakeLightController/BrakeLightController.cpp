#include "Arduino.h"
#include "BrakeLightController.h"

BrakeLightController::BrakeLightController(int sensorPin, int outputPin) {
	pinMode(sensorPin, INPUT_PULLUP);
	pinMode(outputPin, OUTPUT);
	sensor_pin = sensorPin;
	output_pin = outputPin;
}

void BrakeLightController::Update() {
	int sensorVal = digitalRead(sensor_pin);
	digitalWrite(output_pin, sensorVal);
}