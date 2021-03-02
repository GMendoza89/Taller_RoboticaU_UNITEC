#include"Componentes.hpp"

LED::LED(){
  PIN = 13;
  Intensity = 255;
}

LED::LED(unsigned char P){
  PIN = P;
  Intensity = 255;
}
LED::~LED(){}
void LED::SetLed(unsigned char P){PIN = P;}
void LED::SETUP(){
    pinMode(PIN,OUTPUT);
}
void LED::set_intensity(unsigned char I){Intensity = I;}
void LED::Led_ON(){digitalWrite(PIN,HIGH);}
void LED::Led_off(){digitalWrite(PIN,LOW);}
void LED::Led_blink(unsigned int Btime){
  digitalWrite(PIN,HIGH); //Ponemos en alto el pin digital seleccionado
  delay(Btime);               // Espewramos 500 milisegundos
  digitalWrite(PIN,LOW);  //Ponemos en bajo el pin
  delay(Btime);
  return;}
void LED::Led_modulation_on(){
  if(PIN != 3||PIN != 5||PIN != 6||PIN != 9||PIN != 10||PIN != 11)
    return;
  analogWrite(PIN,Intensity);
}
void LED::led_modulation_on(unsigned char I){
  if(PIN != 3||PIN != 5||PIN != 6||PIN != 9||PIN != 10||PIN != 11){
    return;
  }
  Intensity = I;
  analogWrite(PIN,Intensity);
}


Buttom::Buttom(){
  PIN = 3;
}
Buttom::Buttom(unsigned char P){
  PIN = P;
}

Buttom::~Buttom(){
  
}

void Buttom::Set_Buttom(unsigned char P){
  PIN = P;
}

void Buttom::SETUP(){
  pinMode(PIN,INPUT);
}

bool Buttom::read_state(){
  return digitalRead(PIN);
}

