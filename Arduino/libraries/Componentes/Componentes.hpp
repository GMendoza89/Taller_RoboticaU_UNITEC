#ifndef COMPONENTES_HPP
#define COMPONENTES_HPP
#include<Arduino.h>
class LED{
  private:
    unsigned char PIN;
    unsigned char Intensity;
  public:
    LED();
    LED(unsigned char P);
    ~LED();
    void SetLed(unsigned char P);
    void SETUP();
    void set_intensity(unsigned char I);
    void Led_ON();
    void Led_modulation_on();
    void led_modulation_on(unsigned char I);
    void Led_off();
    void Led_blink(unsigned int btime);

  };
class Buttom{
    
    private: 
      unsigned char PIN; 
    public:
      Buttom();
      Buttom(unsigned char P);
      ~Buttom();
      void Set_Buttom(unsigned char P);
      void SETUP();
      bool read_state();
};

#endif
