#include <Arduino_FreeRTOS.h>
#include <CyberFord_Logging.h>
#include <CyberFord_MotorControl.h>
#include <CyberFord_LightControl.h>
#include <CyberFord_RPiControl.h>
#include <CyberFord_SteeringControl.h>

// Prototypes of task definitions
void TaskRPiControl( void *pvParameters );
void TaskLightControl( void *pvParameters );
void TaskSteeringControl( void *pvParameters );
void TaskMotorControl( void *pvParameters );
void TaskLogging( void *pvParameters );

void setup() {
    // init cyberford
    cyberFord_init();

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

void loop() {}  // empty, everything done in tasks

void TaskRPiControl( void *pvParameters ) {
    taskRPiControlMain();
}

void TaskLightControl( void *pvParameters ) {
    taskLightControlMain();
}

void TaskSteeringControl( void *pvParameters ) {
    taskSteeringControlMain();
}

void TaskMotorControl( void *pvParameters ) {
    taskMotorControlMain();
}
    
void TaskLogging( void *pvParameters ) {
    taskLoggingMain();
}