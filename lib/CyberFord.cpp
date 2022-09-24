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
	pinMode(CYBERFORD_PIN_RTURNSIG, OUTPUT);
	pinMode(CYBERFORD_PIN_LTURNSIG, OUTPUT);
	pinMode(CYBERFORD_PIN_REVERSLIGHT, OUTPUT);
	pinMode(CYBERFORD_PIN_BRKLIGHT, OUTPUT);
	pinMode(CYBERFORD_PIN_MOTORDIRA, OUTPUT);
	pinMode(CYBERFORD_PIN_MOTORDIRB, OUTPUT);
	
	// This pin is HIGH when arduino receives a usable command from RPI
	// initial pin state for reset detect is LOW
	pinMode(CYBERFORD_PIN_RESET_DETECT, OUTPUT);
	digitalWrite(CYBERFORD_PIN_RESET_DETECT, LOW);)

	// Configure SPI pins 10(SS), 11(MOSI), 12(MISO), 13(SCK)
	pinMode(CYBERFORD_PIN_RPI_SS, INPUT_PULLUP);
    pinMode(CYBERFORD_PIN_RPI_MISO, OUTPUT);
    // setup SPI peripheral so that arduino is a slave
    SPCR |= _BV(SPE);
    // turn on interrupts
    SPCR |= _BV(SPIE);
  
    SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
	SPI.attachInterrupt();

	//Default car state
	signalStop();
	forwardDrive();
	setMotorSpeed(0);
	signalStop();
	reverseLightOFF();
	brakeLightOFF();
	straightWheels();
}