#ifndef CYBERFORD_MOTORCONTROL_H
#define CYBERFORD_MOTORCONTROL_H

#include "CyberFord.h"

void taskMotorControlMain(void);
void setMotorSpeed(int);
void forwardDrive(void);
void reverseDrive(void);

#endif