#include<Componentes.hpp>
LED_RGB L1(11,10,9);

Pot P_red(A0), P_blue(A1),P_green(A2);
void setup() {
  L1.SETUP();

}

void loop() {
  // put your main code here, to run repeatedly:
  L1.on(P_red.Read()/4,P_blue.Read()/4,P_green.Read()/4);

}
