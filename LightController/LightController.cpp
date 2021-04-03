#include "Arduino.h"
#include "LightController.h"

LightController::LightController(int frontPin,int rearPin,int leftPin,int rightPin) {
	pinMode(frontPin, OUTPUT);
	pinMode(rearPin, OUTPUT);
	pinMode(leftPin, OUTPUT);
	pinMode(rightPin, OUTPUT);
	front_pin = frontPin;
	rear_pin = rearPin;
	left_pin = leftPin;
	right_pin = rightPin;
  blink_start = 0;
}

void LightController::UpdateInput(char charIn) {
	blink_start = millis();
	light = charIn;
	if (charIn == 'F' or charIn == 'B' or charIn == 'L' or charIn == 'R') {
		on = true;
	} else {
		on = false;
	}
	if (charIn == 'L' or charIn == 'R') {
		blink = true;
	} else {
		blink = false;
	}
}

void LightController::Update() {
    digitalWrite(front_pin, LOW);
    digitalWrite(rear_pin, LOW);
    digitalWrite(left_pin, LOW);
    digitalWrite(right_pin, LOW);
	if ((millis() - blink_start) % 1000 < 500) {
		
	}
}