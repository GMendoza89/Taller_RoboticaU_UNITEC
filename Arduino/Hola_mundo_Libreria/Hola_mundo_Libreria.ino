// Taller de Robotica Unitec
//
//Hola Mundo
//
// Autor: Mendoza Pinto Gustavo David

#include<Componentes.hpp>

LED L1(12); //Configuramos Led 1 en el puerto 12

void setup() {
  L1.SETUP(); // Configuramos Led 1 como salida
}

void loop() {
  L1.Led_blink(100); //parapadeamos una vez cada segundo
}
