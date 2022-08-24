#include <Arduino_FreeRTOS.h>

// Prototypes of task definitions
void TaskRPiControl( void *pvParameters );
void TaskLightControl( void *pvParameters );
void TaskSteeringControl( void *pvParameters );
void TaskMotorControl( void *pvParameters );
void TaskLogging( void *pvParameters );

void setup() {
    pinMode(7, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);

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

    vTaskStartScheduler();

}

void loop()

{

}

void TaskRPiControl( void *pvParameters ) {
    for(;;){
        digitalWrite(5, LOW);
        vTaskDelay(2);
    }
}
void TaskLightControl( void *pvParameters ) {
    taskYIELD();
}
void TaskSteeringControl( void *pvParameters ) {
    taskYIELD();
}
void TaskMotorControl( void *pvParameters ) {
    taskYIELD();
}
void TaskLogging( void *pvParameters ) {
    taskYIELD();
}