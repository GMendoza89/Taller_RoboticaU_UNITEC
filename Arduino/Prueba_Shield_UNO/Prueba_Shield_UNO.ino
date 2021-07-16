#include<Robot_Shield_UNO.hpp>

Locomotor LMS;
Ultrasonic S1;

Servo Servo_1;
void setup(){
    LMS.SETUP();
    S1.SETUP();
    Servo_1.attach(servo_signal);
    Serial.begin(9600);
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
    Serial.print("El valor del sensor en mm es: ");
    Serial.println(S1.getDistance(mm));
    Serial.print("El valor del sensor en cm es: ");
    Serial.println(S1.getDistance(cm));
    Serial.print("El valor del sensor en m es: ");
    Serial.println(S1.getDistance(m));
    Serial.print("El valor del sensor sin codigo es: ");
    Serial.println(S1.getDistance(5));
    delay(1000);

    Servo_1.write(0);
    for(int i1 = 0; i1<=180;++i1){
        Servo_1.write(i1);
        delay(10);
    }
    for(int i2 = 180; i2>=0;--i2){
        Servo_1.write(i2);
        delay(10);
    }

}
