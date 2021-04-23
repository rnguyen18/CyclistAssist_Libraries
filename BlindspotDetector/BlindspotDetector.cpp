#include "Arduino.h"
#include "BlindspotDetector.h"
#include "NewPing.h"

BlindspotDetector::BlindspotDetector(int trigPinA, int echoPinA, int trigPinB, int echoPinB) {
	Serial.begin(9600);
	pinMode(echoPinA,INPUT_PULLUP);
	pinMode(echoPinB,INPUT_PULLUP);
	trig_PinA = trigPinA;
	echo_PinA = echoPinA;
	trig_PinB = trigPinB;
	echo_PinB = echoPinB;
	period = 50;
	time_now = 0;
}

int BlindspotDetector::Update() {
	NewPing sonar[SONAR_NUM] = {
			NewPing(trig_PinA, echo_PinA, 500), // NewPing setup of pins and maximum distance.
			NewPing(trig_PinB, echo_PinB, 500)
		};

	//  Read both sonar sensors
  	for (int i = 0; i < SONAR_NUM; i++) {
		if(millis() > time_now + period){   // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
				time_now = millis();
				duration = sonar[i].ping_median();
				distance[i] = sonar[i].convert_in(duration);
		}
	}

	both1 = 0;  // Initialize loop variables
	both2 = 0;
	output = 0x00;
  
	// Categorize each sonar distance level
	for ( int j = 0; j < SONAR_NUM; j++) {
		if(distance[j] >= level_1_low && distance[j] <= level_1_high) {         // Level 1
		output = output | 1;     
		}else if(distance[j] > level_1_high && distance[j] <= level_2_high) {   // Level 2
		output = output | (2 + j*6);
		both1++;
		} else if(distance[j] > level_2_high && distance[j] <= level_3_high) { // Level 3
		output = output | (16 + j*48);
		both2++;
		}
	}

	if(both1 == 2) {
		output = output | 4;
		output = output & 0xF5;
	}

	if(both2 == 2) {
		output = output | 32;
		output = output & 0xAF;
	}
	
	return(output);
}