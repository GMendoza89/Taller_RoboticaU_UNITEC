#include<librobot.hpp>

MotorDC motorDerecho(4,5,6);
MotorDC motorIzquierdo(7,8,9);

HCSR04 sensorUSFC(10,11);
HCSR04 sensorUSFI(2,3);
HCSR04 sensorUSFD(12,13);

// Variables utiizadas en el sensor ultraonico
double lecturaUSFI;
double lecturaUSFC;
double lecturaUSFD;
double umbralUS = 75;

//Sensores Infrarojos
byte sensorIFFD = A2;
byte sensorIFFC = A1;
byte sensorIFFI = A0;
byte sensorIFPC = A3;

int lecturaIFFC;
int lecturaIFFD;
int lecturaIFFI;
int lecturaIFPC;
int umbralDIF = 500;


byte pinActivacion = A4;

//banderas a utilizar
bool on;
bool initCounter;
bool endCounter;
bool ifFD;
bool ifFI;
bool ifFC;
bool ifPC;
bool usFI;
bool usFC;
bool usFD;

// `VARIABLES DE ESTADO
byte estado;

int tiempoInicial;
int tiempoRetardo = 5000;

void setup() {
  // put your setup code here, to run once:
  motorDerecho.setup();
  motorIzquierdo.setup();
  sensorUSFI.setup();
  sensorUSFC.setup(); 
  sensorUSFD.setup(); 
  pinMode(pinActivacion,INPUT);
  Serial.begin(9600);
  on = false;
  initCounter = false;
  endCounter = false;  

}

void loop() {
  //leeemos pin de activación
  on = digitalRead(pinActivacion);

  while(on == true){
    //Verificar desconección
    on = digitalRead(pinActivacion);
    //Lecturas de sensores infrarojos
    lecturaIFFI = analogRead(sensorIFFI);
    lecturaIFFC = analogRead(sensorIFFC);
    lecturaIFFD = analogRead(sensorIFFD);
    lecturaIFPC = analogRead(sensorIFPC);
    //lecturas de los sensores ultrasonicos
    lecturaUSFI = sensorUSFI.getDistance(cm);
    lecturaUSFC = sensorUSFC.getDistance(cm);
    lecturaUSFD = sensorUSFD.getDistance(cm);
    estado = 0;
    //+++++++++++++++++ Comprobación de lecturasd e sensores ++++ Comentar en el código final o quitar ++++++  
    // Serial.print("Lectura de activacion: ");
    // Serial.println(on);
    // Serial.println("Lectura Sensores infrarojo FI | FC | FD | PC");
    // Serial.print(lecturaIFFI);
    // Serial.print(" | ");
    // Serial.print(lecturaIFFC);
    // Serial.print(" | ");
    // Serial.print(lecturaIFFD);
    // Serial.print(" | ");
    // Serial.println(lecturaIFPC);
    // Serial.println(" Lectura de los sensores Ultrasonicos | FI | FC | FD ");
    // Serial.print(lecturaUSFI);
    // Serial.print(" | ");
    // Serial.print(lecturaUSFC);
    // Serial.print(" | ");
    // Serial.println(lecturaUSFD);
    // delay(500);  
    //+++++++++++++++++++++++++++++++++++++++++++++
    //Evaluamos lecturas de sensores infrarojos
    if(lecturaIFFI < umbralDIF){
      ifFI = false;
    }else{
      ifFI = true;
    }
    if(lecturaIFFC < umbralDIF){
      ifFC = false;
    }else{
      ifFC = true;
    }
    if(lecturaIFFD < umbralDIF){
      ifFD = false;
    }else{
      ifFD = true;
    } 
    if(lecturaIFPC < umbralDIF){
      ifPC = false;
    }else{
      ifPC = true;
    }
    //evaluamos lecturas de sensores ultrasoicos
    if(lecturaUSFI < umbralUS){
      usFI = true;
    }else{
      usFI = false;
    }
    if(lecturaUSFC < umbralUS){
      usFC = true;
    }else{
      usFC = false;
    }
    if(lecturaUSFD < umbralUS){
      usFD = true;
    }else{
      usFD = false;
    }
    estado = ifPC << 6 | ifFI << 5 | ifFC << 4 | ifFD << 3 | usFI << 2 | usFC << 1 | usFD; 
    // Secuencia de comprobacion de datos +++++++++++++++++++eliminar o comentar del código final
    // Serial.print("Registro de ESTADO:  ");
    // Serial.println(estado);
    // delay(500);
    //--------------------------------------------------------
    
    if(initCounter == false){
      Serial.println("Iniciamos Conteo de reatrdo");
      tiempoInicial = millis();
      initCounter = true;
    }
    if(endCounter == false){
      if(millis() - tiempoInicial < tiempoRetardo){
        Serial.println("Esperando a finalizacion de reatardo");
        continue;
      }else{
        Serial.println("Finaliza Tiempo de espera a los golpes");
        endCounter = true;
        
      }
    }
    
    // Iniciamos Algoritmo de Control

    if(estado>= 64){
      Serial.print("Linea Posterior detectada detectada");
      //Movimiento de los motores al frente a maxima potencia
      motorDerecho.move(1,255);
      motorIzquierdo.move(1,255);
      continue;
    }
    if(estado >= 8){
      Serial.print("Linea Frontal detectada detectada");
      motorDerecho.move(2,255);
      motorIzquierdo.move(2,255);
      continue;
    }
    switch(estado){
      case 1: // Dectectado por el lado Derecho
        Serial.print("Enemigo detectado a la derecha");
        motorDerecho.move(1,150);
        motorIzquierdo.move(1,200);
        break;
      case 2: // Dectectado por el lado Derecho
        Serial.print("Enemigo detectado al Frente");
        motorDerecho.move(1,200);
        motorIzquierdo.move(1,200);
        break;
      case 3: // Dectectado por el lado Derecho
        Serial.print("Enemigo detectado la derecha");
        motorDerecho.move(1,175);
        motorIzquierdo.move(1,200);
        break;
     case 4: // Dectectado por el lado Derecho
        Serial.print("Enemigo detectado a la izquierda");
        motorDerecho.move(1,200);
        motorIzquierdo.move(1,150);
        break;
     case 5: // Dectectado por el lado Derecho
        Serial.print("Enemigo detectado al frente");
        motorDerecho.move(1,200);
        motorIzquierdo.move(1,200);
        break;
     case 6: // Dectectado por el lado Derecho
        Serial.print("Enemigo detectado por la izquierda");
        motorDerecho.move(1,200);
        motorIzquierdo.move(1,175);
        break;
     case 7: // Dectectado por el lado Derecho
        Serial.print("Enemigo detectado al frente");
        motorDerecho.move(1,200);
        motorIzquierdo.move(1,200);
        break;
     default : // Sin enemigo detectado
        Serial.print("Buscando Enemigo");
        motorDerecho.move(1,200);
        motorIzquierdo.move(2,200);
        break;
       
    }  
  }
}
