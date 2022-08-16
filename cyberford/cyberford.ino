// Include Arduino FreeRTOS library
#include <Arduino_FreeRTOS.h>

// Include Cyber Ford libraries
#include <CyberFord.h>
#include <CyberFord_RPiControl.h>
#include <CyberFord_LightControl.h>
#include <CyberFord_SteeringControl.h>
#include <CyberFord_MotorControl.h>
#include <CyberFord_Logging.h>

// Prototypes of task definitions
void TaskRPiControl( void *pvParameters );
void TaskLightControl( void *pvParameters );
void TaskSteeringControl( void *pvParameters );
void TaskMotorControl( void *pvParameters );
void TaskLogging( void *pvParameters );

// Instantiate CyberFord object which will serve as interface for control
cyberFord CyberFord;

void setup() {
  // Call startup routine for the CyberFord object
  CyberFord.startup();

  // RPi control - Task creation
  xTaskCreate( TaskRPiControl, "RPiControl", 128, NULL, 3, NULL );
  //Light control - Task creation
  xTaskCreate( TaskLightControl, "LightControl", 128, NULL, 1, NULL );
  // Steering control - Task creation
  xTaskCreate( TaskSteeringControl, "SteeringControl", 128, NULL, 2, NULL );
  // Motor control - Task creation
  xTaskCreate( TaskMotorControl, "MotorControl", 128, NULL, 2, NULL );
  // Logging - Task creation
  xTaskCreate( TaskLogging, "Logging", 128, NULL, 1, NULL );
}

void loop() {} // Not used, everything done in tasks


// RPi control task definition
void TaskRPiControl( void *pvParameters ) { 
  for(;;) {
    CyberFord.setTurnAngle(40);
    CyberFord.setCommand(commandTurnRight);
    vTaskDelay(1);
    //CyberFord.setCommand(commandMotorSetForwardDrive);
    //vTaskDelay(1);
  }
}

// Light control task definition
void TaskLightControl( void *pvParameters ) {
  for(;;) {
    if(CyberFord.getCommand() == commandLeftTurnSignal)
      CyberFord.leftTurnSignal();
    
    else if(CyberFord.getCommand() == commandRightTurnSignal)
      CyberFord.rightTurnSignal();
    
    else if(CyberFord.getCommand() == commandStopSignal)
      CyberFord.stopSignal();
  }
}

// Steering control task definition
void TaskSteeringControl( void *pvParameters ) {
  for(;;) {
    if(CyberFord.getCommand() == commandTurnLeft)
      CyberFord.turnLeft( CyberFord.getTurnAngle() );
    
    else if(CyberFord.getCommand() == commandTurnRight)
      CyberFord.turnRight( CyberFord.getTurnAngle() );
  }
}

// Motor control task definition
void TaskMotorControl( void *pvParameters ) {
  for(;;) {
    if(CyberFord.getCommand() == commandMotorSetSpeed)
      CyberFord.motorSpeed( CyberFord.getSpeed() );
    
    else if(CyberFord.getCommand() == commandMotorSetForwardDrive)
      CyberFord.driveForward();
    
    else if(CyberFord.getCommand() == commandMotorSetReverseDrive)
      CyberFord.driveReverse();
  }
}

// Logging task definition
void TaskLogging( void *pvParameters ) {
  for(;;) {
    vTaskDelay(500);
  }
}
