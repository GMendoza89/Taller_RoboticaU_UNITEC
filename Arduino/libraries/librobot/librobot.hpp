/*
*   Name: librobot
*
*   Description: Componentes para operar un robot
*   Autor: Ing. Gustavo David Mendoza Pinto
*   version: 0.1.0
*
*/
#ifndef LIBROBOT
#define LIBROBOT


#include<Arduino.h>

#define SPEED_OF_SOUND_M  0.000344 // Velocidad del sonido en m/uS
#define SPEED_OF_SOUND_CM  0.0344 // Velocidad del sonido en m/uS
#define SPEED_OF_SOUND_MM  0.344 // Velocidad del sonido en m/uS

#define mm 0
#define cm 1
#define m 2

class MotorDC{
  private:
  byte pinA;
  byte pinB;
  byte pinEn;
  
  public:
  MotorDC(byte A, byte B, byte EN);
  ~MotorDC();
  void setup();
  void move(byte type, byte vel);
  
};

class HCSR04{
  private:
  	byte echo;
  	byte trigger;
  	long int tiempo;
  	double distancia;
  public:
  	HCSR04(byte pinTrigger, byte pinEcho);
  	~HCSR04();
  	void setup();
  	double getDistance(unsigned int units);
};




#endif