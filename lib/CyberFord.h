#ifndef CYBERFORD_H
#define CYBERFORD_H

#include "Arduino.h"
#include "Arduino_FreeRTOS.h"
#include <SPI.h>
#include <CyberFord_Logging.h>
#include <CyberFord_MotorControl.h>
#include <CyberFord_LightControl.h>
#include <CyberFord_RPiControl.h>
#include <CyberFord_SteeringControl.h>

#define SOFTWARE_VER	"0.0.0"		// Update on software version release. Do not remove quotations.
#define BAUD_RATE_BPS   115200UL

// Pin defines
#define CYBERFORD_PIN_STEERING      9   // PWM pin
#define CYBERFORD_PIN_RLIMSW        1   // GPIO pin
#define CYBERFORD_PIN_LLIMSW        2   // GPIO pin
#define CYBERFORD_PIN_RTURNSIG      4   // GPIO pin
#define CYBERFORD_PIN_LTURNSIG      5   // GPIO pin
#define CYBERFORD_PIN_REVERSLIGHT   0   // GPIO pin
#define CYBERFORD_PIN_BRKLIGHT      6   // GPIO pin
#define CYBERFORD_PIN_MOTORDIRA     7   // GPIO pin
#define CYBERFORD_PIN_MOTORDIRB     8   // GPIO pin
#define CYBERFORD_PIN_MOTORSPEED    3   // PWM pin
#define CYBERFORD_PIN_RPI_SS        10  // GPIO pin
#define CYBERFORD_PIN_RPI_MOSI      11
#define CYBERFORD_PIN_RPI_MISO      12
#define CYBERFORD_PIN_RPI_SCK       13

// enum definitions for all possible commands to the CyberFord
enum command_e {
    commandLeftTurnSignal,
    commandRightTurnSignal,
    commandStopSignal,
    commandTurnLeft,
    commandTurnRight,
    commandMotorSetSpeed,
    commandMotorSetForwardDrive,
    commandMotorSetReverseDrive,
};

void printReleaseInfo(void);
void cyberFord_init(void);


#endif