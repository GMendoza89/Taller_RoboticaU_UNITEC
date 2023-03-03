
/*
*   Name: librobot
*
*   Description: Componentes para operar un robot
*   Autor: Ing. Gustavo David Mendoza Pinto
*   version: 0.1.0
*
*/
#include<librobot.hpp>



MotorDC::MotorDC(byte A, byte B, byte EN){
        pinA = A;
        pinB = B;
        pinEn = EN;};
MotorDC::~MotorDC(){};
void MotorDC::setup(){
            pinMode(pinA,OUTPUT);
            pinMode(pinB,OUTPUT);
            pinMode(pinEn,OUTPUT);};
void MotorDC::move(byte type, byte vel){
    switch(type){   
        case 0:
            digitalWrite(pinA,LOW);
            digitalWrite(pinB,LOW);
            analogWrite(pinEn,vel);
        break;
        case 1:
            digitalWrite(pinA,HIGH);
            digitalWrite(pinB,LOW);
            analogWrite(pinEn,vel);
        break;
        case 2:
            digitalWrite(pinA,LOW);
            digitalWrite(pinB,HIGH);
            analogWrite(pinEn,vel);
        break;
        default:
            digitalWrite(pinA,LOW);
            digitalWrite(pinB,LOW);
            analogWrite(pinEn,0);
        break;  
        } 
};


HCSR04::HCSR04(byte pinTrigger, byte pinEcho){
    trigger = pinTrigger;
    echo = pinEcho;};
HCSR04::~HCSR04(){ };
void HCSR04::setup(){
    pinMode(trigger,OUTPUT);
    pinMode(echo,INPUT);
    };
double HCSR04::getDistance(unsigned int units){
    digitalWrite(trigger,LOW);
    delayMicroseconds(2);
    digitalWrite(trigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger,LOW);
    tiempo = pulseIn(echo,HIGH);
    
    switch (units)
    {
        case mm:
            distancia = tiempo*SPEED_OF_SOUND_MM/2.0;
            break;

        case cm:
            distancia = tiempo*SPEED_OF_SOUND_CM/2.0;
            break;

        case m:
            distancia = tiempo*SPEED_OF_SOUND_M/2.0;
            break;
        
        default:
            distancia = tiempo*SPEED_OF_SOUND_M/2.0;
            break;
    }
    return distancia;
};