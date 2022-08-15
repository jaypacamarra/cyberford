// Include Arduino FreeRTOS library
#include <Arduino_FreeRTOS.h>

// Include Cyber Ford libraries
#include <CyberFord_TaskCreation.h>
#include <CyberFord_Wrapper.h>
#include <CyberFord_RPiControl.h>
#include <CyberFord_LightControl.h>
#include <CyberFord_SteeringControl.h>
#include <CyberFord_MotorControl.h>
#include <CyberFord_Logging.h>

// Prototypes of task definitions

void setup() {
  // Print release info

  // Initialize serial communication for logging
  // Logging will also be send wirelessly via SPI
  
  // RPi control - Task creation
  // Light control - Task creation
  // Steering control - Task creation
  // Motor control - Task creation
  // Logging - Task creation

  // Init RPi object
  // Init Light control object
  // Init Steering control object
  // Init Motor control object
  // Init Logging object
}

void loop() {} // Not used, everything done in tasks

// RPi control task definition
// Light control task definition
// Steering control task definition
// Motor control task definition
// Logging task definition
