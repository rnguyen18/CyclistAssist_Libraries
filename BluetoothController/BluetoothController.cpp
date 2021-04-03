#include "Arduino.h"
#include "BluetoothController.h"
#include "SoftwareSerial.h"

BluetoothController::BluetoothController(int rxPin,int txPin) : mySerial(SoftwareSerial(rxPin, txPin)) {
	Serial.begin(9600);
	rx_pin = rxPin;
	tx_pin = txPin;
	mySerial.begin(9600);
	Serial.write("BluetoothController Initialized\n");
}


void BluetoothController::Write(char char_output) {
    mySerial.write(char_output);
}

char BluetoothController::Read() {
	char char_input = ' ';
	if (mySerial.available() > 0) {
		char_input = mySerial.read();
		Serial.write(char_input);
	}
    return char_input;
}