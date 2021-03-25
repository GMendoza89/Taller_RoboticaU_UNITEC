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

//---------------------------- Shift Register 74HC595 --------------------------

shiftR74HC595::shiftR74HC595(){
  latchPin = 8;
  clockPin = 11;
  dataPin = 12;
}
shiftR74HC595::shiftR74HC595(unsigned char ST_CP,unsigned char SH_CP, unsigned char DS){
  latchPin = ST_CP;
  clockPin = SH_CP;
  dataPin = DS;
}
shiftR74HC595::~shiftR74HC595(){ 

}
void shiftR74HC595::SETUP(){
  // set all pins as output
  pinMode(latchPin,OUTPUT); //latch pin
  pinMode(clockPin,OUTPUT); // clock pin
  pinMode(dataPin,OUTPUT); // data pin
  Serial.begin(9600);
  Serial.print("Registro de desplazamiento configurado ");
  Serial.print("latch pin: ");
  Serial.print(latchPin);
  Serial.print(" ");
  Serial.print("clock pin: ");
  Serial.print(clockPin);
  Serial.print(" ");
  Serial.print("latch pin: ");
  Serial.print(dataPin);
  Serial.println(" ");
}
void shiftR74HC595::shiftO(byte *data){
  bool data_state = LOW;
  digitalWrite(dataPin,LOW);
  digitalWrite(clockPin, LOW);
Serial.println("Enviando datos");
  for(int i0 = 7; i0 >= 0; i0--){
    digitalWrite(clockPin,LOW);

    data_state = bitRead(*data,i0);
    digitalWrite(dataPin,data_state);
    Serial.print("enviando dato[");
    Serial.print(i0);
    Serial.print("] = ");
    Serial.println(data_state);

    digitalWrite(clockPin,HIGH);

    digitalWrite(clockPin,LOW);
  }

  digitalWrite(clockPin,LOW);

}
void shiftR74HC595::shiftOut(byte dataout){

  digitalWrite(latchPin,LOW);
  shiftO(&dataout);
  digitalWrite(latchPin,HIGH);

}
void shiftR74HC595::shiftOut_2Bytes(word dataout){
  
  data_l = lowByte(dataout);
  data_h = highByte(dataout);
  digitalWrite(latchPin,LOW);
  shiftO(&data_h);
  shiftO(&data_l);
  digitalWrite(latchPin,HIGH);

}
void shiftR74HC595::shiftOut_2Bytes(byte data_hight, byte data_low){
  digitalWrite(latchPin,LOW);
  shiftO(&data_hight);
  shiftO(&data_low);
  digitalWrite(latchPin,HIGH);
}
void shiftR74HC595::blinkAll(unsigned char n_blink,unsigned int blink_time){
  data_h = 0xff;
  data_l = 0x00;
  Serial.println("Prepaprando parpadeo de los 8 leds");
  digitalWrite(latchPin,LOW);
  shiftO(&data_l);
  digitalWrite(latchPin,HIGH);
  delay(200);

  for(unsigned char i0 = 0; i0<n_blink;i0++){
    digitalWrite(latchPin,LOW);
    shiftO(&data_h);
    digitalWrite(latchPin,HIGH);
    delay(blink_time);
    digitalWrite(latchPin,LOW);
    shiftO(&data_l);
    digitalWrite(latchPin,HIGH);
    delay(blink_time);
  }

}
void shiftR74HC595::blinkAll_2bytes(unsigned char n_blink,unsigned int blink_time){
  data_h = 0xff;
  data_l = 0x00;
  digitalWrite(latchPin,LOW);
  shiftO(&data_l);
  shiftO(&data_l);
  digitalWrite(latchPin,HIGH);
  delay(200);

  for(unsigned char i0 = 0; i0<n_blink;i0++){
    digitalWrite(latchPin,LOW);
    shiftO(&data_h);
    shiftO(&data_h);
    digitalWrite(latchPin,HIGH);
    delay(blink_time);
    digitalWrite(latchPin,LOW);
    shiftO(&data_l);
    shiftO(&data_l);
    digitalWrite(latchPin,HIGH);
    delay(blink_time);
  }
}
//--------------------------- Ultrasonic Sensor HC-SR04 -------------------------------
ultrasonico::ultrasonico(){
  TRIG = 2;
  ECHO= 3;

}
ultrasonico::ultrasonico(unsigned char T, unsigned char G){
  TRIG = T;
  ECHO= G;

}
ultrasonico::~ultrasonico(){

}

void ultrasonico::SETUP(){
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);

}
int ultrasonico::Distancia(){
    digitalWrite(TRIG,LOW);
    delay(2);
    digitalWrite(TRIG,HIGH);
    delay(10);
    digitalWrite(TRIG,LOW);

    TIEMPO = pulseIn(ECHO,HIGH);

    // V = Distancia recorrida/Tiempo que tardamos
    // v = (34 m/seg) 
    // TIEMPO = PULSO 
    // DISTANCIA = V*TIEMPO/2;

    distancia = velocidad*TIEMPO/2;
    return distancia;
}

//-------------------------- DC Motor -------------------------------------------------

DC_Motor::DC_Motor(){
  Motor_A = 2;
  Motor_En = 3;
  Motor_B = 4;
  Power_Motor = 0;
}
DC_Motor::DC_Motor(byte A, byte B, byte En){
  Motor_A = A;
  Motor_En = En;
  Motor_B = B;
  Power_Motor = 0;
}
DC_Motor::~DC_Motor(){}
void DC_Motor::SETUP(){

  pinMode(Motor_A,OUTPUT);
  pinMode(Motor_B,OUTPUT);
  pinMode(Motor_En,OUTPUT);

}
void DC_Motor::SET_POWER(byte PWD){Power_Motor = PWD;}
void DC_Motor::Move(bool direction){

  if(direction){
    digitalWrite(Motor_A,HIGH);
    digitalWrite(Motor_B,LOW);
  }else{
    digitalWrite(Motor_A,LOW);
    digitalWrite(Motor_B,HIGH);
  }
  analogWrite(Motor_En,Power_Motor);

}
void DC_Motor::Move(bool direction, byte POWER){

  Power_Motor = POWER;
  if(direction){
    digitalWrite(Motor_A,HIGH);
    digitalWrite(Motor_B,LOW);
  }else{
    digitalWrite(Motor_A,LOW);
    digitalWrite(Motor_B,HIGH);
  }
  analogWrite(Motor_En,Power_Motor);
}
void DC_Motor::STOP(){
  digitalWrite(Motor_A,HIGH);
  digitalWrite(Motor_B,HIGH);
}
void DC_Motor::OFF(){
  digitalWrite(Motor_A,LOW);
  digitalWrite(Motor_B,LOW);
}