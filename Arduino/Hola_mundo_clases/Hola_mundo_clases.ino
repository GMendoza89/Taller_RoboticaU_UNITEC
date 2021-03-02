// Taller de Robotica Unitec
//
//Hola Mundo
//
// Autor: Mendoza Pinto Gustavo David

void blinking(int pin,int Btime);
int led = 13;

class LED{
  private:
    unsigned char PIN;
    unsigned char Intensity;
  public:
    LED();
    LED(unsigned char P);
    ~LED();
    void SetLed(unsigned char P);
    void set_intensity(unsigned char I);
    void Led_ON();
    void Led_off();
    void Led_blink(unsigned int btime);

  };

void setup() {
  
pinMode(led,OUTPUT); //Habilitamos el pin 13 como salida digital
}

void loop() {
  blinking(led,500);
  
}


void blinking(int pin, int Btime){
  digitalWrite(pin,HIGH); //Ponemos en alto el pin digital seleccionado
  delay(Btime);               // Espewramos 500 milisegundos
  digitalWrite(pin,LOW);  //Ponemos en bajo el pin
  delay(Btime);
  return;
}

LED::LED(){
  PIN = 13;
  Intensity = 255;
}

LED::LED(unsigned char P){
  PIN = P;
  Intensity = 255;
}

void LED::SetLed(unsigned char P){PIN = P;}
void LED::set_intensity(unsigned char I){Intensity = I;}
void LED::Led_ON(){digitalWrite(PIN,HIGH);}
void LED::Led_off(){digitalWrite(PIN,LOW);}
void LED::Led_blink(unsigned int Btime){
  digitalWrite(PIN,HIGH); //Ponemos en alto el pin digital seleccionado
  delay(Btime);               // Espewramos 500 milisegundos
  digitalWrite(PIN,LOW);  //Ponemos en bajo el pin
  delay(Btime);
  return;}
