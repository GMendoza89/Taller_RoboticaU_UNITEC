#include<Robot_Shield_UNO.hpp>

Locomotor LMS(0.0275,0.130,90);
Ultrasonic S1;

//Servo Servo_1;
long int old_time = 0;
long int present_time;
void setup(){
    
    //Servo.detach();
    //Servo_1.attach(10);
    LMS.SETUP();
    LMS.SETUP_Odom();
    LMS.Salmple_Time = 200; // Frecuencia de muestreo 200 mS 5 Hz
    S1.SETUP();
    Serial.begin(9600);    
}

void loop(){
//    LMS.MOVE(MOVE_FORWARD);
//    delay(1000);
//    LMS.MOVE(MOVE_BACKWARD);
//    delay(1000);
    present_time = millis();
    
    if(present_time - old_time>= LMS.Salmple_Time){
      noInterrupts();
      LMS.Odom();
      LMS.Vel();
      old_time = present_time;
      interrupts();
      
    }
    LMS.MOVE(MOVE_FORWARD,124,124);
    
//    LMS.MOVE(MOVE_FORWARD,50,150);
//    delay(1000);
//    Serial.print("El valor del sensor en mm es: ");
//    Serial.println(S1.getDistance(mm));
//    Serial.print("El valor del sensor en cm es: ");
//    Serial.println(S1.getDistance(cm));
//    Serial.print("El valor del sensor en m es: ");
//    Serial.println(S1.getDistance(m));
//    Serial.print("El valor del sensor sin codigo es: ");
//    Serial.println(S1.getDistance(5));
//    delay(1000);

   

}
