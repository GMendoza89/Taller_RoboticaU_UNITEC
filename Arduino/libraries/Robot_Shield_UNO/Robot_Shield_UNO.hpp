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



class Locomotor{
    private:



    public:

    Locomotor();
    ~Locomotor();

    void SETUP();
    void MOVE(int move);

    void MOVE(int move, byte PM1, byte PM2);


};


#endif