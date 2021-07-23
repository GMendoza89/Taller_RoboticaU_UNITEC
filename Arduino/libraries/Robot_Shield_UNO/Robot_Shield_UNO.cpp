#include<Robot_Shield_UNO.hpp>

//variablesglobales para utilizar en las funciones de los encoder

long int step_m1;
long int step_m2;

bool direction_m1; // booleano que indica el signo positivo es en direccion hacia adelante, falso es direccion contraria.
bool direction_m2;

// long int steps_m1; //pasos para estimar la posicion, el signo indica el sentido en que se ha avanzado
//long int step_m2_t;


//Funciones globales para encoder

void step_counter_M1(){
    direction_m1?++step_m1:--step_m1;
}
void step_counter_M2(){
    direction_m2?++step_m2:--step_m2;
}
//------------------------------------- Clase del sistema locomotor ----------------------------------------------
Locomotor::Locomotor(){
    radius = 0;
    length = 0;
    step_per_radius = 20;
}
Locomotor::Locomotor(double r, double l){
    radius = r;
    length = l;
    step_per_radius = 20;
}
Locomotor::Locomotor(double r, double l, long int N){
    radius =r;
    length = l;
    step_per_radius = N;
}

Locomotor::~Locomotor(){

}
void Locomotor::SETUP(){
    pinMode(Motor_1_A,OUTPUT);
    pinMode(Motor_1_B,OUTPUT);
    pinMode(Motor_2_A,OUTPUT);
    pinMode(Motor_2_B,OUTPUT);

    pinMode(En_Motor_1,OUTPUT);
    pinMode(En_Motor_2,OUTPUT);
}
void Locomotor::SETUP_Odom(){
    attachInterrupt(digitalPinToInterrupt(I_Endoder_1),step_counter_M1,FALLING);
    attachInterrupt(digitalPinToInterrupt(I_Endoder_2),step_counter_M2,FALLING); 
    delta_R_steps = 0; 
    delta_L_steps = 0;
    L_steps_past = 0;
    R_steps_past = 0;                         
    vr = 0; 
    vl = 0; 
    base_Distance = 0;                                                 
    R_distance=0; 
    L_distance= 0;
    R_distance_past=0; 
    L_distance_past=0;
    x =0;
    y = 0;
    theta = 0;
}
void Locomotor::MOVE(int move){

    analogWrite(En_Motor_1,150);
    analogWrite(En_Motor_2,150);
    
    switch (move)
    {
    case 0:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,LOW);
        break;
    
    case 1:
        
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,LOW);
        direction_m1 = true;
        direction_m2 = true;

        break;

    case 2:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,HIGH);
        direction_m1 = false;
        direction_m2 = false;
        break;
    case 3:       
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,HIGH);
        break;
    default:
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,LOW);
        break;
    }
}
void Locomotor::MOVE(int move, byte PM1, byte PM2){

    analogWrite(En_Motor_1,PM1);
    analogWrite(En_Motor_2,PM2);
    
    switch (move)
    {
    case 0:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,LOW);
        break;
    
    case 1:
        
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,LOW);
        direction_m1 = true;
        direction_m2 = true;
        break;

    case 2:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,HIGH);
        direction_m1 = false;
        direction_m2 = false;
        break;
    case 3:       
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,HIGH);
        break;
    default:
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,LOW);
        break;
    }
}
void Locomotor::Odom(){
    delta_R_steps = step_m2 - R_steps_past;                                 // calculo cambio pasos
    delta_L_steps = step_m1 - L_steps_past;
    // Serial.print(step_m2);
    // Serial.print(",");
    // Serial.println(step_m1);

    L_distance = pi*2*radius*(delta_L_steps/((double)step_per_radius));    // Distancia L
    R_distance = pi*2*radius*(delta_R_steps/((double)step_per_radius));    // Distancia R

    base_Distance = (R_distance+L_distance)/2;                              // distanciade labase del robot

    x += base_Distance*cos(theta);
    y += base_Distance*sin(theta);

    theta += (R_distance - L_distance)/length;
    theta = atan2(sin(theta),cos(theta));

    R_steps_past = step_m2;
    L_steps_past = step_m1;

    //  Serial.print(x);
    //  Serial.print(",");
    //  Serial.println(y);

}

void Locomotor::Vel(){


    vr = 1000*(R_distance)/Salmple_Time;
    vl = 1000*(L_distance)/Salmple_Time;

    // Serial.print(step_m2);
    // Serial.print(",");
    // Serial.println(step_m1);
    
    // Serial.print(R_distance);
    // Serial.print(",");
    // Serial.println(L_distance);

    Serial.print(vr);
    Serial.print(",");
    Serial.println(vl);


}

//------------------------------ Ultrasonic class ------------------------------------------------------------------

Ultrasonic::Ultrasonic(){
    Distance = 0;
    Time = 0;
}
Ultrasonic::~Ultrasonic(){
    
}
void Ultrasonic::SETUP(){
    pinMode(TRIG,OUTPUT);
    pinMode(ECHO,INPUT);
}

float Ultrasonic::getDistance(int units){

    digitalWrite(TRIG,LOW);
    delay(2);
    digitalWrite(TRIG,HIGH);
    delay(10);
    digitalWrite(TRIG,LOW);

    Time = pulseIn(ECHO,HIGH);

    switch (units)
    {
    case mm:
        Distance = Sound_speed_mm*Time/2;    
        break;
    
    case cm:
        Distance = Sound_speed_cm*Time/2;    
        break;

    case m:
        Distance = Sound_speed_m*Time/2;    
        break;

    default:
        Distance = -1;
        break;
    }
    return Distance;
    

}