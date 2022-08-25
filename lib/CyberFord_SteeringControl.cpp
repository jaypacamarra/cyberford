#include "CyberFord_SteeringControl.h"

static Servo myservo;

void taskSteeringControlMain(void) {
    myservo.attach(CYBERFORD_PIN_STEERING);

    for(;;) {
        if(cyberFord_getCommand() == commandTurnLeft)
            leftTurn( cyberFord_getCommandValue() );
        
        else if(cyberFord_getCommand() == commandTurnRight)
            rightTurn( cyberFord_getCommandValue() );
    }
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