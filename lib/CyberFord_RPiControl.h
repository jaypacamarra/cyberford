#ifndef CYBERFORD_RPICONTROL_H
#define CYBERFORD_RPICONTROL_H

#include <SPI.h>
#include "Arduino.h"
#include "CyberFord.h"

#define commandID_unknownCommand    (-1)
#define commandValue_unknownCommand (-1)
#define vehicleID_unknownVehicle    (-1)
#define vehicleID_cyberFord         (0x1)

// structure for grouping SPI data after bit math
typedef struct RPiControlStruct {
    int commandID;
    int commandValue;
} structInstanceRPiControl;

void taskRPiControlMain(void);
int cyberFord_getCommand(void);
int cyberFord_getCommandValue(void);

#endif