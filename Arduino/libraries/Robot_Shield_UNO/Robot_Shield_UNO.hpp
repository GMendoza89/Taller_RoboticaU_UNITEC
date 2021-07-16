/*
*   Name: ROBOT_SHIELD_UNO

*   Description: Libreria para usarse con la shield diseñada para Arduino UNO.
*   la cual tiene integrado pines para conectar 1 sensor ultrasonico HC-SR04, 
*   2 motoreductores o moteres en dc, 1 servomoteres, una tira de 6 sensores 
*   de deteccion de linea, un módulo Bluetooth HC06. Para el taller de robótica
*   de UNITEC campus Querétaro.
*   Autor: Ing. Gustavo David Mendoza Pinto
*
*
*
*
*/
#ifndef ROBOT_SHIELD_UNO
#define ROBOT_SHIELD_UNO

// Librerias necesarias
#include<Arduino.h>
#include<Servo.h>

// definicion de pines a utilizar

#define I_Endoder_1 2
#define I_Endoder_2 3

#define Motor_1_A 4
#define Motor_1_B 5
#define Motor_2_A 7
#define Motor_2_B 8

#define En_Motor_1 6
#define En_Motor_2 9

// Valriables de globales

#define MOVE_RELEASE 0
#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define MOVE_STOP 3
#define MOVE_RIGH 4
#define MOVE_LEFT 5

#define servo_signal 10

#define ECHO 13
#define TRIG 12

#define mm 0
#define cm 1
#define m 2

#define pi 3.1416
#define Sound_speed_mm 0.0034
#define Sound_speed_cm 0.034
#define Sound_speed_m 0.34


void step_counter_M1();
void step_counter_M2();


class Locomotor{
    private:
    float radius; //Radio de las Rudas
    float length; // distancia entre los radios
    int step_per_radius;

    public:

    Locomotor();
    Locomotor(float r, float l);
    ~Locomotor();

    void SETUP();
    void SETUP_E();
    void MOVE(int move);

    void MOVE(int move, byte PM1, byte PM2);


};

class Ultrasonic{
    private:

    public:
    Ultrasonic();
    ~Ultrasonic();
    void SETUP();
    float Distance(int units);

};

#endif