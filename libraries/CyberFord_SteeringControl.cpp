#include "CyberFord_SteeringControl.h"

Servo myservo;

void initSteeringServo(void) {
    myservo.attach(CYBERFORD_PIN_STEERING);
}

void straightWheels(void) {
    myservo.write(90);
}

void leftTurn(int degree) {
    myservo.write(degree);
}

void rightTurn(int degree) {
    myservo.write(degree);
}