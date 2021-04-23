#include "Arduino.h"
#include "LightController.h"

LightController::LightController(int headlightPin, int leftPin, int rightPin, int rearPin) {
	pinMode(headlightPin, OUTPUT);
	pinMode(leftPin, OUTPUT);
	pinMode(rightPin, OUTPUT);
	pinMode(rearPin, OUTPUT);
	headlight_pin = headlightPin;
	left_pin = leftPin;
	right_pin = rightPin;
	rear_pin = rearPin;
	blink_start = 0;
	headlight = false;
	blinkers = false;
	light = ' ';
}

void LightController::UpdateInput(char charIn) {
	if (charIn != ' ') {
		switch(charIn) {
			case('L'):
			case('R'):
			case('B'):
				blink_start = millis();
				light = charIn;
				blinkers = true;
				break;
			case('H'):
				headlight = true;
				break;
			case('l'):
			case('r'):
			case('b'):
				blinkers = false;
				break;
			case('h'):
				headlight = false;
				break;
			case('C'):
				headlight = false;
				blinkers = false;
				light = charIn;
		}
	}
}

void LightController::Update() {
	if (headlight) {
		digitalWrite(headlight_pin, HIGH);
		digitalWrite(rear_pin, HIGH);
	} else {
		digitalWrite(headlight_pin, LOW);
		digitalWrite(rear_pin, LOW);
	}
	
	if ((blinkers & ((millis() - blink_start) % BLINKER_TIMING < (BLINKER_TIMING/2)))) {
		switch (light) {
			case 'L': digitalWrite(left_pin, HIGH);
					  digitalWrite(right_pin, LOW);
					  break;
			case 'R': digitalWrite(right_pin, HIGH);
					  digitalWrite(left_pin, LOW);
					  break;
			case 'B': digitalWrite(right_pin, HIGH);
					  digitalWrite(left_pin, HIGH);
					  break;
		}
	} else {
		digitalWrite(left_pin, LOW);
		digitalWrite(right_pin, LOW);
	}
}

bool LightController::CheckHeadlightStatus() {
	return headlight;
}