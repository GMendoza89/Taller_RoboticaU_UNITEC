#include"Led.hpp"

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
void LED::led_setup(){
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

