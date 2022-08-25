#ifndef CYBERFORD_STEERINGCONTROL_H
#define CYBERFORD_STEERINGCONTROL_H

#include "Arduino.h"
#include "CyberFord.h"
#include "Servo.h"

void taskSteeringControlMain(void);
void leftTurn(int);
void rightTurn(int);

#endif