#ifndef CYBERFORD_RPICONTROL_H
#define CYBERFORD_RPICONTROL_H

#include <SPI.h>
#include "Arduino.h"
#include "CyberFord.h"

#define vehicleID_unknownVehicle    (0x0)
#define vehicleID_cyberFord         (0x1)

// structure for grouping SPI data after bit math
typedef struct RPiControlStruct {
    int commandID;
    int commandValue;
} structInstanceRPiControl;

int parseVehicleID(int);
int parseCommandID(int);
int parseCommandValue(int);

#endif