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

// Global task handle definitions
TaskHandle_t taskNotificationHandlerRPiControl;

// Instantiate CyberFord object which will serve as interface for control
cyberFord CyberFord;

void setup() {
  // Call startup routine for the CyberFord object
  CyberFord.startup();

  // RPi control - Task creation
  xTaskCreate( TaskRPiControl, "RPiControl", 128, NULL, 3, &taskNotificationHandlerRPiControl );
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
    CyberFord.setCommand( commandLeftTurnSignal );
    CyberFord.setCommandValue( 50 );
    vTaskDelay(3);
    // if(ulTaskNotifyTake(pdTRUE, portMAX_DELAY)) { //ulTaskNotifyTake blocks task until notification is received
    //   byte spiData = SPDR;
    //   bool readyForCommandIDAndValue = false;
    //   int nextByte = 0;

    //   //verify vehicle ID from spi data coming from RPI
    //   //6 spiData bytes will need to be sent sequentially into the verifyVehicleID function
    //   if(CyberFord.verifyVehicleID(spiData)) {
    //     readyForCommandIDAndValue = true;
    //   }
      
    //   if(readyForCommandIDAndValue) {
    //     //set command ID
    //     if(nextByte == 1) {
    //       CyberFord.setCommand((command)spiData);
    //     }

    //     //set command value
    //     else if(nextByte == 2) {
    //       CyberFord.setCommandValue((int)spiData);

    //       //reset flag and nextByte counter for next command
    //       readyForCommandIDAndValue = false;
    //       nextByte = 0;

    //       // Give other tasks cpu time by blocking this task
    //       vTaskDelay(3);
    //     }

    //     //increment byte counter once vehicle ID is verified
    //     nextByte++;
    //   }
    // }    
  }
}

// Light control task definition
void TaskLightControl( void *pvParameters ) {
  for(;;) {
    if(CyberFord.getCommand() == commandLeftTurnSignal) {
      do {
        CyberFord.leftTurnSignal();
      }while(CyberFord.getCommand() != commandStopSignal);
    }
    else if(CyberFord.getCommand() == commandRightTurnSignal) {
      do {
        CyberFord.rightTurnSignal();
      }while(CyberFord.getCommand() != commandStopSignal);
    }
    CyberFord.stopSignal();
  }
}

// Steering control task definition
void TaskSteeringControl( void *pvParameters ) {
  for(;;) {
    if(CyberFord.getCommand() == commandTurnLeft)
      CyberFord.turnLeft( CyberFord.getCommandValue() );
    
    else if(CyberFord.getCommand() == commandTurnRight)
      CyberFord.turnRight( CyberFord.getCommandValue() );
  }
}

// Motor control task definition
void TaskMotorControl( void *pvParameters ) {
  for(;;) {
    if(CyberFord.getCommand() == commandMotorSetSpeed)
      CyberFord.motorSpeed( CyberFord.getCommandValue() );
    
    else if(CyberFord.getCommand() == commandMotorSetForwardDrive)
      CyberFord.driveForward();
    
    else if(CyberFord.getCommand() == commandMotorSetReverseDrive)
      CyberFord.driveReverse();
  }
}

// Logging task definition
void TaskLogging( void *pvParameters ) {
  for(;;) {
    Serial.print( "Command ID: " );
    Serial.print( CyberFord.getCommand() );
    Serial.print( "\t" );
    Serial.print( "Command Value: " );
    Serial.println( CyberFord.getCommandValue() );
  }
}
