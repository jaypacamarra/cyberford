#include "CyberFord_LightControl.h"

void signalLeft(void) {
    digitalWrite(CYBERFORD_PIN_RTURNSIG, LOW);
    digitalWrite(CYBERFORD_PIN_LTURNSIG, HIGH);
    vTaskDelay(50);
    digitalWrite(CYBERFORD_PIN_LTURNSIG, LOW);
    vTaskDelay(50);
}

void signalRight(void) {
    digitalWrite(CYBERFORD_PIN_LTURNSIG, LOW);
    digitalWrite(CYBERFORD_PIN_RTURNSIG, HIGH);
    vTaskDelay(50);
    digitalWrite(CYBERFORD_PIN_RTURNSIG, LOW);
    vTaskDelay(50);
}

void signalStop(void) {
    digitalWrite(CYBERFORD_PIN_LTURNSIG, LOW);
    digitalWrite(CYBERFORD_PIN_RTURNSIG, LOW);
}