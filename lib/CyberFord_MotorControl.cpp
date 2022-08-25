#include "CyberFord_MotorControl.h"


void taskMotorControlMain(void) {
    for(;;) {
        if(cyberFord_getCommand() == commandMotorSetSpeed)
            setMotorSpeed( cyberFord_getCommandValue() );
        
        else if(cyberFord_getCommand() == commandMotorSetForwardDrive)
            forwardDrive();
        
        else if(cyberFord_getCommand() == commandMotorSetReverseDrive)
            reverseDrive();
    }
}

void setMotorSpeed(int speed) {
    speed = min(255, max(0, speed));
    analogWrite(CYBERFORD_PIN_MOTORSPEED, speed);
}

void forwardDrive(void) {
    digitalWrite(CYBERFORD_PIN_MOTORDIRA, HIGH);
    digitalWrite(CYBERFORD_PIN_MOTORDIRB, LOW);
}

void reverseDrive(void) {
    digitalWrite(CYBERFORD_PIN_MOTORDIRA, LOW);
    digitalWrite(CYBERFORD_PIN_MOTORDIRB, HIGH);
}