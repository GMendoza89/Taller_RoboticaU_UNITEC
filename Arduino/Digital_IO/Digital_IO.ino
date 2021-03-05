#include<Componentes.hpp>

LED L1(12);
LED L_red(11);
LED L_green(10);
LED L_blue(9);

Buttom Boton_1(8);
Buttom b_red(6);
Buttom b_green(5);
Buttom b_blue(4);

void setup() {
  // put your setup code here, to run once:
  L1.SETUP();
  L_red.SETUP();
  L_green.SETUP();
  L_blue.SETUP();
  Boton_1.SETUP();
  b_red.SETUP();
  b_green.SETUP();
  b_blue.SETUP();
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Boton_1.Read()){
    L1.on();
  }else{
    L1.off();
  }
  if(b_red.Read()){
    L_red.on();
  }
  else{
    L_red.off();
  }
  if(b_red.Read()){
    L_red.on();
  }
  else{
    L_red.off();
  }
  if(b_green.Read()){
    L_green.on();
  }
  else{
    L_green.off();
  }
  if(b_blue.Read()){
    L_blue.on();
  }
  else{
    L_blue.off();
  }

}
