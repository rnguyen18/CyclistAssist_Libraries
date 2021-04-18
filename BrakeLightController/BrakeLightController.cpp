#include "Arduino.h"
#include "LightController.h"

BrakeLightController::BrakeLightController(int sensorPin, int outputPin) {
	pinMode(sensorPin, INPUT_PULLUP);
	pinMode(outputPin, OUTPUT);
	Serial.write("BrakeLightController Initialized\n");
}

void BrakeLightController::Update() {
	int sensorVal = digitalRead(sensorPin);
	digitalWrite(outputPin, sensorVal);
}