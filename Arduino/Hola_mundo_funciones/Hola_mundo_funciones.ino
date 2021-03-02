// Taller de Robotica Unitec
//
//Hola Mundo
//
// Autor: Mendoza Pinto Gustavo David

void blinking(int pin,int Btime);
int led = 12;



void setup() {
  
pinMode(led,OUTPUT); //Habilitamos el pin 13 como salida digital
}

void loop() {
  blinking(led,250);
  
}


void blinking(int pin, int Btime){
  digitalWrite(pin,HIGH); //Ponemos en alto el pin digital seleccionado
  delay(Btime);               // Espewramos 500 milisegundos
  digitalWrite(pin,LOW);  //Ponemos en bajo el pin
  delay(Btime);
  return;
}
