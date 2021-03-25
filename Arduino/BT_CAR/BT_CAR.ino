#include<Componentes.hpp>

//Declaracion de sensores 
ultrasonico FrontalIzquierdo(35,34);    // Sensor Frontal izquierdo 
ultrasonico Frontal(37,36);             // Sensor frontal 
ultrasonico FrontalDerecho(39,38);      // Sensor frontal derecho

//Declaración de actuadores
DC_Motor MotorDerecho(32,33,3);         //Motor Derecho
DC_Motor MotorIzquierdo(30,31,2);       //Motor Izquierdo

// Declaracion de Variables a utilizar
unsigned char Control;                  // Variable donde se guardan los datos del bluetooth
byte Velocidad;                         // Variable de velocidad del robot
byte Diferencia;

void setup(){
    FrontalIzquierdo.SETUP();           // Configuracion de pines para sensor izquierdo
    Frontal.SETUP();                    // Configuracion de pines para sensor frontal
    FrontalDerecho.SETUP();             // Configuracion de pines para sensor derecho
    MotorDerecho.SETUP();               // Configuracion de pines para motor derecho
    MotorIzquierdo.SETUP();             // Configuracion de pines para motor izquierdo
    Serial.begin(9600);                 // estableciendo comunicacion serial con la computadora
    Serial1.begin(9600);                // estableciendo comunicacion serial con el módulo Bluetooth
    Velocidad = 128;                     // establecemos la velocidad a aproximada mente 1/2 de la potencia
    Diferencia = Velocidad/2;            // establecemos la diferencia para los giros en 1/2 de la velocidad
}
void loop(){
//Descomentar y comentar lo demas par prueba de sensores
/*  
    Serial.print("Distancia Sensor Frontal Izquierdo: ");
    Serial.println(FrontalIzquierdo.Distancia());
    Serial.print("Distancia Sensor Frontal: ");
    Serial.println(Frontal.Distancia());
    Serial.print("Distancia Sensor Frontal Derecho: ");
    Serial.println(FrontalDerecho.Distancia());
*/
//Prueva de Motores descomentar esta seccion y comentar lo demas
 /*  
    MotorDerecho.Move(MOVE_FORWARD,125);
    MotorIzquierdo.Move(MOVE_FORWARD,125);
    delay(1000);
    MotorDerecho.OFF();
    MotorIzquierdo.OFF();
    delay(250);
    MotorDerecho.Move(MOVE_BACKWARD,125);
    MotorIzquierdo.Move(MOVE_BACKWARD,125);
    delay(1000);
*/

// Seccion de control por medio de módulo Bluetooth

    if(Serial1.available()){ // Leemos la variable de entrada del Bluetooth
        Control = Serial1.read();
    }
    switch (Control)
    {
    case 'A': // Opción para avansar hacia adelante
        MotorDerecho.Move(MOVE_FORWARD,Velocidad);
        MotorIzquierdo.Move(MOVE_FORWARD,Velocidad);
        Serial.println("Avansando hacia adelante");
        break;
    
    case 'r': // Opsión para ir en reversa
        MotorDerecho.Move(MOVE_BACKWARD,Velocidad);
        MotorIzquierdo.Move(MOVE_BACKWARD,Velocidad);
        Serial.println("Avansando hacia atras");
        break;
    
    case 'E': // Opsion para avansar en dirección derecha
        MotorDerecho.Move(MOVE_FORWARD,Diferencia);
        MotorIzquierdo.Move(MOVE_FORWARD,Velocidad);
        Serial.println("Avansando hacia adelante y a la derecha");
        break;

    case 'Q': // Opsion para avansar en dirección Izquierda
        MotorDerecho.Move(MOVE_FORWARD,Velocidad);
        MotorIzquierdo.Move(MOVE_FORWARD,Diferencia);
        Serial.println("Avansando hacia adelante y a la izquierda");
        break;
    case 'I': // Opsion para giro Izquierda
        MotorDerecho.Move(MOVE_FORWARD,Velocidad);
        MotorIzquierdo.Move(MOVE_BACKWARD,Velocidad);
        Serial.println("Giro a la izquierda");
        break;

    case 'D': // Opsion para avansar en dirección derecha
        MotorDerecho.Move(MOVE_BACKWARD,Velocidad);
        MotorIzquierdo.Move(MOVE_FORWARD,Velocidad);
        Serial.println("Giro a la Derecha");
        break;
    
    case 'Z': // Opsion para ATRAS Y  dirección IZQUIERDA
        MotorDerecho.Move(MOVE_BACKWARD,Velocidad);
        MotorIzquierdo.Move(MOVE_BACKWARD,Diferencia);
        Serial.println("Direccion reversa y a la Izquierda");
        break;
    
    case 'C': // Opsion para ATRAS Y  dirección derecha
        MotorDerecho.Move(MOVE_BACKWARD,Diferencia);
        MotorIzquierdo.Move(MOVE_BACKWARD,Velocidad);
        Serial.println("Direccion reversa y a la Derecha");
        break;
    
    case 'B': // Opsion para ATRAS Y  dirección derecha
        MotorDerecho.STOP();
        MotorIzquierdo.STOP();
        Serial.println("Freno");
        break;
    
    case '1': // Opsion para ATRAS Y  dirección derecha
        Velocidad = 128;
        Diferencia = Velocidad/2;
        Serial.println("Velocidad en primera");
        break;
    case '2': // Opsion para ATRAS Y  dirección derecha
        Velocidad = 192;
        Diferencia = Velocidad/2;
        Serial.println("Velocidad en segunda");
        break;
    case '3': // Opsion para ATRAS Y  dirección derecha
        Velocidad = 255;
        Diferencia = Velocidad/2;
        Serial.println("Velocidad en Tercera");
        break;
    
    default:    // caso default simplemente apagamos los motores
        MotorDerecho.OFF();
        MotorIzquierdo.OFF();
        Serial.println("Motores Apagados");
        break;
    }

}