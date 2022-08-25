#include "CyberFord_LightControl.h"

void taskLightControlMain(void) {
    for(;;){
        if(cyberFord_getCommand() == commandLeftTurnSignal) {
            signalLeft();
        }
        else if(cyberFord_getCommand() == commandRightTurnSignal) {
            signalRight();
        }
        else if(cyberFord_getCommand() == commandStopSignal) {
            signalStop();
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