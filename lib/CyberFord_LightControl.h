#ifndef CYBERFORD_LIGHTCONTROL_H
#define CYBERFORD_LIGHTCONTROL_H

#include "CyberFord.h"
#include "Arduino.h"
#include "Arduino_FreeRTOS.h"

void taskLightControlMain(void);
void signalLeft(void);
void signalRight(void);
void signalStop(void);

#endif