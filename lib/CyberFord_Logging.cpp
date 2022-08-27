#include "CyberFord_Logging.h"
#include "CyberFord_LightControl.h"

void taskLoggingMain(void) {
    
    for(;;) {
        Serial.print(cyberFord_getCommand());
        Serial.print("\t");
        Serial.println(cyberFord_getCommandValue());
        vTaskDelay(5);
    }
}
