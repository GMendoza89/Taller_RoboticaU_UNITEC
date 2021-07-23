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
*/
#ifndef ROBOT_SHIELD_UNO
#define ROBOT_SHIELD_UNO

// Librerias necesarias
#include<Arduino.h>
#include<Servo.h>
#include<math.h>
// definicion de pines a utilizar

#define I_Endoder_1 2                                                              // Pines para motores
#define I_Endoder_2 3

#define Motor_1_A 4
#define Motor_1_B 5
#define Motor_2_A 7
#define Motor_2_B 8

#define En_Motor_1 6
#define En_Motor_2 11

// Valriables de globales

#define MOVE_RELEASE 0                                                              // Valores para indicar tipo de movimiento
#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define MOVE_STOP 3
#define MOVE_RIGH 4
#define MOVE_LEFT 5             

#define servo_signal 10                                                             // pin para señal de servo

#define ECHO 13                                                                     // pin echo de sensor ultrasonico
#define TRIG 12                                                                     // pin de trig de sensor ultrasonico

#define mm 0                                                                        // conntantes para indicar unidades de valor de retorno de sensor ultrasonico
#define cm 1
#define m 2

#define pi 3.1415926535897932384626433832795                                        // constnate valor de Pi
#define Sound_speed_mm 0.344                                                        // constante velocidad del sonido en mm/mS
#define Sound_speed_cm 0.0344                                                       // constante velocidad del sonido en cm/mS
#define Sound_speed_m 0.000344                                                      // constante velocidad del sonido en m/mS


void step_counter_M1();                                                             // Funcion de interrrupsion para le motor 1
void step_counter_M2();                                                             //Funcion de interrupcion para motor 2


class Locomotor{
    private:
    double radius;                                                                   //Radio de las Rudas
    double length;                                                                   // distancia entre los radios
    long int step_per_radius, delta_R_steps, delta_L_steps;                         // variables para medir los pasos
    long int L_steps_past,R_steps_past;
    double vr, vl;                                                 // varioables para meadir la velocidad
    double base_Distance,R_distance, L_distance,R_distance_past, L_distance_past;   // variables pra medir la distancia
    double x,y,theta;
    double x_past, y_past, theta_past;


    

    public:
    int Salmple_Time;
    Locomotor();                                                                    // contructor por defecto
    Locomotor(double r, double l);                                                    // constructor con parametros
    Locomotor(double r, double l, long int N);
    ~Locomotor();

    void SETUP();                                                                   //funcion que configura las salidas de los motores
    void SETUP_Odom();                                                              // Funcion que configura los encoder                                                                 
    void MOVE(int move);                                                            // funcion de movimiento de los motores
    void MOVE(int move, byte PM1, byte PM2);                            
    
    void Odom();                                                                    //funcion que calcula la odometria
    void Vel();                                                                     // funcion que calcula la velocidad de los motores
    
};

class Ultrasonic{
    private:
    float Distance;
    long int Time;

    public:
    Ultrasonic();
    ~Ultrasonic();
    void SETUP();
    float getDistance(int units);

};

#endif