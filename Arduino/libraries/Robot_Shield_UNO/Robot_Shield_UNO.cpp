#include<Robot_Shield_UNO.hpp>

//variablesglobales para utilizar en las funciones de los encoder

long int counter_m1;
long int counter_m2;

bool direction_m1; // booleano que indica el signo positivo es en direccion hacia adelante, falso es direccion contraria.
bool direction_m2;

long int counter_m1_t; //pasos para estimar la posicion, el signo indica el sentido en que se ha avanzado
long int counter_m2_t;


//Funciones globales para encoder

void step_counter_M1(){
    ++counter_m1;
    if(direction_m1){
        ++counter_m1_t;
    }else{
        --counter_m1_t;
    }

}
void step_counter_M2(){
    ++counter_m2;
    if(direction_m2){
        ++counter_m2_t; 
    }else{
        --counter_m2_t;
    }
}

Locomotor::Locomotor(){
    radius = 0;
    length = 0;
    step_per_radius = 20;
}
Locomotor::Locomotor(float r, float l){
    radius = r;
    length = l;
    step_per_radius = 20;
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
void Locomotor::SETUP_E(){
    attachInterrupt(digitalPinToInterrupt(I_Endoder_1),step_counter_M1,FALLING);
    attachInterrupt(digitalPinToInterrupt(I_Endoder_2),step_counter_M2,FALLING);
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
        break;

    case 2:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,HIGH);
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
        break;

    case 2:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,HIGH);
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