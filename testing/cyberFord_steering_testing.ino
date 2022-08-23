#include <Servo.h>

Servo myservo;

void setup() {
    myservo.attach(9);
}

void loop() {
    int angle = 90;
    int i = 0;

    #define UP      (1)
    #define DOWN    (0)
    bool dir = UP;

    //myservo.write(45);

    for(;;) {
        myservo.write(angle + i);

        if(dir==UP)
            i++;    
        else if(dir==DOWN)
            i--;
        
        if(i==45)
            dir=DOWN;
        if(i==-45)
            dir=UP;

        delay(500); 
    }
}