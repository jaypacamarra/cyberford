#include "CyberFord_LightControl.h"

void taskLightControlMain(void) {
    for(;;){
        // Turn signals
        if(cyberFord_getCommand() == commandLeftTurnSignal) {
            signalLeft();
        }
        else if(cyberFord_getCommand() == commandRightTurnSignal) {
            signalRight();
        }
        else if(cyberFord_getCommand() == commandStopSignal) {
            signalStop();
        }
        
        // Reverse light
        if(cyberFord_getCommand() == commandMotorSetForwardDrive) {
            reverseLightOFF();
        }
        else if(cyberFord_getCommand() == commandMotorSetReverseDrive) {
            reverseLightON();
        }

        // Brake light
        if(cyberFord_getCommand() == commandMotorSetSpeed) {
            if(cyberFord_getCommandValue() == 0) {
                brakeLightON();
            }
            else {
                brakeLightOFF();
            }
        }
    }
}

void signalLeft(void) {
    digitalWrite(CYBERFORD_PIN_RTURNSIG, LOW);
    digitalWrite(CYBERFORD_PIN_LTURNSIG, HIGH);
    vTaskDelay(BLINK_INTERVAL);
    digitalWrite(CYBERFORD_PIN_LTURNSIG, LOW);
    vTaskDelay(BLINK_INTERVAL);
}

void signalRight(void) {
    digitalWrite(CYBERFORD_PIN_LTURNSIG, LOW);
    digitalWrite(CYBERFORD_PIN_RTURNSIG, HIGH);
    vTaskDelay(BLINK_INTERVAL);
    digitalWrite(CYBERFORD_PIN_RTURNSIG, LOW);
    vTaskDelay(BLINK_INTERVAL);
}

void signalStop(void) {
    digitalWrite(CYBERFORD_PIN_LTURNSIG, LOW);
    digitalWrite(CYBERFORD_PIN_RTURNSIG, LOW);
}

void reverseLightOFF(void) {
    digitalWrite(CYBERFORD_PIN_REVERSLIGHT, LOW);
}

void reverseLightON(void) {
    digitalWrite(CYBERFORD_PIN_REVERSLIGHT, HIGH);
}

void brakeLightOFF(void) {
    digitalWrite(CYBERFORD_PIN_BRKLIGHT, LOW);
}

void brakeLightON(void) {
    digitalWrite(CYBERFORD_PIN_BRKLIGHT, HIGH);
}