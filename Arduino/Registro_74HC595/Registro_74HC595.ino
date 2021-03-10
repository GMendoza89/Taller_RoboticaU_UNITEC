#include<Componentes.hpp>

shiftR74HC595 R1(7,8,12);


byte data_l;
byte data_h;
unsigned int b_time = 250;
int i0 = 0;

void setup() {
  
  R1.SETUP();

  R1.blinkAll2(2,500);

}

void loop() {
  
  // put your main code here, to run repeatedly:
  //data = 0x00;
  if(i0<8){
      bitSet(data,i0);
  }else{
      i0 = 0;
      data = 0x00;
      R1.shiftOut(data);
      delay(b_time);
      return;
  }
  R1.shiftOut(data);
  i0++;
  delay(b_time);

}
