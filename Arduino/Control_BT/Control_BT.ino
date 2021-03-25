#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
int motor_1_A = 8;
int motor_1_B = 7;
int en_motor_1 = 9;
char Data;
void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado
  pinMode(motor_1_A, OUTPUT);
  pinMode(motor_1_B, OUTPUT);
  pinMode(en_motor_1, OUTPUT);
  Serial.begin(9600);   // Inicializamos  el puerto serie  
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Data = BT.read();
  }

switch (Data)
{
case 'A':
    digitalWrite(motor_1_A,HIGH);
    digitalWrite(motor_1_B,LOW);
    analogWrite(en_motor_1,125);
    Serial.println("Avansando hacia el frente");
    break;

default:
    digitalWrite(motor_1_A,LOW);
    digitalWrite(motor_1_B,LOW);
    analogWrite(en_motor_1,125);
    break;
}
}
