#ifndef CYBERFORD_LIGHTCONTROL_H
#define CYBERFORD_LIGHTCONTROL_H

#include "CyberFord.h"
#include "Arduino.h"
#include "Arduino_FreeRTOS.h"

#define BLINK_INTERVAL  50

void taskLightControlMain(void);
void reverseLightOFF(void);
void reverseLightON(void);
void brakeLightOFF(void);
void brakeLightON(void);
void signalLeft(void);
void signalRight(void);
void signalStop(void);

#endif