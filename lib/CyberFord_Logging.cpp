#include "CyberFord_Logging.h"
#include "CyberFord_LightControl.h"
void taskLoggingMain(void) {
    for(;;) {
        Serial.println(cyberFord_getCommand());
        vTaskDelay(5);
    }
}