#include "CyberFord_RPiControl.h"

// SPI interrupt routine for SPI commands from RPi
// Unblocks the RPI control task
extern TaskHandle_t taskNotificationHandlerRPiControl;
ISR (SPI_STC_vect)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    vTaskNotifyGiveFromISR(taskNotificationHandlerRPiControl, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken) {
        taskYIELD();    // force context switch
    }
}

int parseVehicleID(int charIn) {
    // define static buffer of characters, fills up if first byte is ascii character 'C'
    // and fills up to form the 6 ascii character sequence of 'CyberF'
    static char charBuff[6] = {0, 0, 0, 0, 0, 0};
    static int charPos = 0;
    static int vehicleID = 0;   //0 = no match, 1 = cyberFord ID

    //  C   y   b   e   r   F
    //  0   1   2   3   4   5
    if(charIn == 'C') {
        charBuff[charPos] = charIn;
        charPos++;
    }
    else if(charBuff[0] == 'C' and charIn == 'y') {
        charBuff[charPos] = charIn;
        charPos++;
    }
    else if(charBuff[1] == 'y' and charIn == 'b') {
        charBuff[charPos] = charIn;
        charPos++;
    }  
    else if(charBuff[2] == 'b' and charIn == 'e') {
        charBuff[charPos] = charIn;
        charPos++;
    }
    else if(charBuff[3] == 'e' and charIn == 'r') {
        charBuff[charPos] = charIn;
        charPos++;
    }
    else if(charBuff[4] == 'r' and charIn == 'F') {
        charBuff[charPos] = charIn;
        vehicleID = vehicleID_cyberFord;
    }
    else {
        // Unknown vehicle detected
        vehicleID = vehicleID_unknownVehicle;
        for(int i=0; i<6 ; i++)
            charBuff[i] = 0;
    }

    return vehicleID;
}

int parseCommandID(int) {
    ;
}

int parseCommandValue(int) {
    ;
}