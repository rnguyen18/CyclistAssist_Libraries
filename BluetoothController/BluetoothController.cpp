#include "Arduino.h"
#include "BluetoothController.h"
#include "SoftwareSerial.h"

BluetoothController::BluetoothController(int rxPin,int txPin) : mySerial(SoftwareSerial(rxPin, txPin)) {
	rx_pin = rxPin;
	tx_pin = txPin;
	mySerial.begin(9600);
	buffer = "";
}

void BluetoothController::WriteString(String string_output) {
	buffer = buffer+string_output;
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

void BluetoothController::Update() {
	if (buffer.length() > 1) {
		buffer.toCharArray(send_byte, 2);
		buffer = buffer.substring(1);
		mySerial.write(send_byte);
		Serial.write(send_byte);
	} else if (buffer.length() == 1) {
		buffer.toCharArray(send_byte, 2);
		buffer = "";
		mySerial.write(send_byte);
		Serial.write(send_byte);
	}
}