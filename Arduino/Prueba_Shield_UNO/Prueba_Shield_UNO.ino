#include<Robot_Shield_UNO.hpp>

Locomotor LMS;

void setup(){
    LMS.SETUP();
}

void loop(){
    LMS.MOVE(MOVE_FORWARD);
    delay(1000);
    LMS.MOVE(MOVE_BACKWARD);
    delay(1000);
    LMS.MOVE(MOVE_FORWARD,150,50);
    delay(1000);
    LMS.MOVE(MOVE_FORWARD,50,150);
    delay(1000);
}
