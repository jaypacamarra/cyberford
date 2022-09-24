#include "CyberFord_RPiControl.h"


static byte databuff[2] = {0, 0};

static int xCommandID = commandID_unknownCommand;
static int xCommandValue = commandValue_unknownCommand;

static byte data;
static unsigned int i = 0;
static bool commandReadyToProcess = false;

// SPI interrupt routine for SPI commands from RPi
// Unblocks the RPI control task
ISR (SPI_STC_vect) {
    if(0xFF == SPDR) {   // rpi ready byte received
        i=0;
        digitalWrite(CYBERFORD_PIN_RESET_DETECT, HIGH);     // Let Rpi know it can send actual commands now
    }

    if(i == 0) {
        databuff[0] = SPDR;
        i++;
    }
    else if(i == 1) {
        databuff[1] = SPDR;
        i=0;
        commandReadyToProcess = true;
    }
}

void taskRPiControlMain(void) {
    for(;;){
        if(commandReadyToProcess) {
            xCommandID = databuff[0];
            xCommandValue = databuff[1];

            commandReadyToProcess = false;
        }
        else {
            taskYIELD();
        }

        vTaskDelay(1);
    }
}

int cyberFord_getCommand(void) {
    return xCommandID;
}

int cyberFord_getCommandValue(void) {
    return xCommandValue;
}