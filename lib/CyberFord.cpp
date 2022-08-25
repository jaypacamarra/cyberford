#include "CyberFord.h"
#include <Servo.h>

void printReleaseInfo(void) {
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

void cyberFord_init(void) {
	// Initialize serial communication for logging
	// Logging will also be send wirelessly via SPI
	Serial.begin(BAUD_RATE_BPS);

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
}