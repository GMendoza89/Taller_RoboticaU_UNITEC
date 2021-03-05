#include"Componentes.hpp"
//-------------------------------------------------------------------------
LED::LED(){
  PIN = 13;
  Intensity = 255;
}

LED::LED(unsigned char P){
  PIN = P;
  Intensity = 255;
}
LED::~LED(){}
void LED::SET(unsigned char P){PIN = P;}
void LED::SETUP(){
    pinMode(PIN,OUTPUT);
}

void LED::on(){digitalWrite(PIN,HIGH);}
void LED::off(){digitalWrite(PIN,LOW);}
void LED::BLINK(unsigned int Btime){
  digitalWrite(PIN,HIGH); //Ponemos en alto el pin digital seleccionado
  delay(Btime);               // Espewramos 500 milisegundos
  digitalWrite(PIN,LOW);  //Ponemos en bajo el pin
  delay(Btime);
  return;}
void LED::on_pwm(){
  if(PIN != 3||PIN != 5||PIN != 6||PIN != 9||PIN != 10||PIN != 11)
    return;
  analogWrite(PIN,Intensity);
}
void LED::on_pwm(unsigned char I){
  if(PIN != 3||PIN != 5||PIN != 6||PIN != 9||PIN != 10||PIN != 11){
    return;
  }
  Intensity = I;
  analogWrite(PIN,Intensity);
}
//-------------------------------------------------------------------------------

LED_RGB::LED_RGB(){
  channel_red = 11;
  channel_blue = 10;
  channel_green = 9;
}
LED_RGB::LED_RGB(unsigned char R, unsigned char B, unsigned char G){
  channel_red = R;
  channel_blue = B;
  channel_green = G;
  brightness_red = 255;
  brightness_blue = 255;
  brightness_green = 255;
}
LED_RGB::~LED_RGB(){

}

void LED_RGB::SET(unsigned char R, unsigned char B, unsigned char G){
  channel_red = R;
  channel_blue = B;
  channel_green = G;
  brightness_red = 255;
  brightness_blue = 255;
  brightness_green = 255;
}
void LED_RGB::SETUP(){
  pinMode(channel_red,OUTPUT);
  pinMode(channel_blue,OUTPUT);
  pinMode(channel_green,OUTPUT);
}
void LED_RGB::Set_brightness(unsigned char BR, unsigned char BB, unsigned char BG){
  brightness_red = BR;
  brightness_blue = BB;
  brightness_green = BG;
}
void LED_RGB::off(){
  digitalWrite(channel_red,LOW);
  digitalWrite(channel_blue,LOW);
  digitalWrite(channel_green,LOW);
}
void LED_RGB::on(){
  digitalWrite(channel_red,HIGH);
  digitalWrite(channel_blue,HIGH);
  digitalWrite(channel_green,HIGH);
}
void LED_RGB::on(unsigned char BR, unsigned char BB, unsigned char BG){
  analogWrite(channel_red,BR);
  analogWrite(channel_blue,BB);
  analogWrite(channel_green,BG);
}
void LED_RGB::on_birghtness(){
  analogWrite(channel_red,brightness_red);
  analogWrite(channel_blue,brightness_blue);
  analogWrite(channel_green,brightness_blue);
}
void LED_RGB::on_r(){
  analogWrite(channel_red,brightness_red);
}
void LED_RGB::on_b(){
  analogWrite(channel_blue,brightness_blue);
}
void LED_RGB::on_g(){
  analogWrite(channel_blue,brightness_blue);
}
void LED_RGB::off_r(){
  digitalWrite(channel_red,LOW);
}
void LED_RGB::off_b(){
  digitalWrite(channel_blue,LOW);
}
void LED_RGB::off_g(){
  digitalWrite(channel_green,LOW);
}
//------------------------------------------------------------------------------
Buttom::Buttom(){
  PIN = 3;
}
Buttom::Buttom(unsigned char P){
  PIN = P;
}

Buttom::~Buttom(){
  
}

void Buttom::SET(unsigned char P){
  PIN = P;
}

void Buttom::SETUP(){
  pinMode(PIN,INPUT);
}

bool Buttom::Read(){
  return digitalRead(PIN);
}
//-----------------------------------------------------------------------------

Pot::Pot(){
  analog_value = A0;
}
Pot::Pot(unsigned char AX){
  analog_value = AX;
}
Pot::~Pot(){

}
int Pot::Read(){
  return analogRead(analog_value);
}
unsigned char Pot::pwm_value(){return analogRead(analog_value)/4;}
