#include "CyberFord.h"
#include <Servo.h>

void cyberFord::setSoftwareVer() {
	softwareVer = SOFTWARE_VER;
}

void cyberFord::setBaudRate() {
	baudRate = BAUD_RATE_BPS;
}

String cyberFord::getSoftwareVer(void) {
	return softwareVer;
}

unsigned long cyberFord::getBaudRate(void) {
	return baudRate;
}

void cyberFord::printReleaseInfo(void) {
	// Product
	Serial.println("CyberFord 2022 AEV (C) 2022");

	// Organization
	Serial.println("Made by JetPac Industries");

	// Software version
	Serial.print("Software release version: "); 
	Serial.println(SOFTWARE_VER);

	// Additional info
	Serial.println("This project was motivated by Tesla's Cyber Truck.");
}

void cyberFord::startup(void) {
	// Initialize serial communication for logging
	// Logging will also be send wirelessly via SPI
	Serial.begin(BAUD_RATE_BPS);

	setSoftwareVer();
	setBaudRate();
	printReleaseInfo();
	
	/* Note, PWM pins are left out of pinMode configuration because they do not need
		to be initialized as outputs. Additionally, the SPI pins 11,12,13 are
		configured automatically by calling the SPI.begin() function.
	*/
	pinMode(CYBERFORD_PIN_RLIMSW, INPUT_PULLUP);
	pinMode(CYBERFORD_PIN_LLIMSW, INPUT_PULLUP);
	pinMode(CYBERFORD_PIN_RTURNSIG, OUTPUT);
	pinMode(CYBERFORD_PIN_LTURNSIG, OUTPUT);
	pinMode(CYBERFORD_PIN_BRKLIGHT, OUTPUT);
	pinMode(CYBERFORD_PIN_MOTORDIRA, OUTPUT);
	pinMode(CYBERFORD_PIN_MOTORDIRB, OUTPUT);

	// Configure SPI pins 10(SS), 11(MOSI), 12(MISO), 13(SCK)
	pinMode(CYBERFORD_PIN_RPI_SS, OUTPUT);
	SPI.begin();
	SPI.attachInterrupt();

	// activate steering servo
	initSteeringServo();

	// default drive mode
	motorSpeed(0);
	straightenWheels();

}

void cyberFord::setCommand(command cmd) {
	commandID = cmd;
}

command cyberFord::getCommand(void) {
	return commandID;
}

void cyberFord::setCommandValue(int val) {
	commandValue = val;
}

int cyberFord::getCommandValue(void) {
	return commandValue;
}

void cyberFord::leftTurnSignal(void) {
	signalLeft();
}

void cyberFord::rightTurnSignal(void) {
	signalRight();
}

void cyberFord::stopSignal(void) {
	signalStop();
}

void cyberFord::straightenWheels(void) {
	straightWheels();
}

void cyberFord::turnLeft(int deg) {
	int ang = min(180, max(0, deg));
	leftTurn(90 - ang);
}

void cyberFord::turnRight(int deg) {
	int ang = min(180, max(0, deg));
	rightTurn(90 + ang);
}

void cyberFord::motorSpeed(int spd) {
	setMotorSpeed(spd);
}

void cyberFord::driveForward(void) {
	forwardDrive();
}

void cyberFord::driveReverse(void) {
	reverseDrive();
}

void cyberFord::setSpeed(int spd) {
	speedSetpoint = spd;
}

int cyberFord::getSpeed(void) {
	return speedSetpoint;
}

void cyberFord::setTurnAngle(int angle) {
	turnAngle = angle;
}

int cyberFord::getTurnAngle(void) {
	return turnAngle;
}

int cyberFord::verifyVehicleID(byte data) {
	parseVehicleID(data);
}