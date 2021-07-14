#include<Robot_Shield_UNO.hpp>

Locomotor::Locomotor(){

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