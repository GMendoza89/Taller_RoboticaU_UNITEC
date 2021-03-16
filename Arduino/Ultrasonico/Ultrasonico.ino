#include<Componentes.hpp>
// int echo = 7;
// int trig = 8;

// float tiempo;
// float Distancia=0;
ultrasonico U1(8,7);
ultrasonico U2(9,10);
ultrasonico U3(11,12);

float D;
void setup(){
    // pinMode(echo,INPUT);
    // pinMode(trig,OUTPUT);
    U1.SETUP();
    U2.SETUP();
    U3.SETUP();
    Serial.begin(9600);


}
void loop(){
    // digitalWrite(trig,LOW);
    // delay(2);
    // digitalWrite(trig,HIGH);
    // delay(10);
    // digitalWrite(trig,LOW);

    // tiempo = pulseIn(echo,HIGH);

     // V = Distancia recorrida/Tiempo que tardamos
     // v = (34 m/seg) 
     // TIEMPO = PULSO 
     // DISTANCIA = V*TIEMPO/2;

    // Distancia = 0.034*tiempo/2;
    D = U1.Distancia();
    Serial.print("Distancia 1: ");
    Serial.println(D);
    D = U2.Distancia();
    Serial.print("Distancia 2: ");
    Serial.println(D);
    D = U3.Distancia();
    Serial.print("Distancia 3: ");
    Serial.println(D);
}