#ifndef COMPONENTES_HPP
#define COMPONENTES_HPP
#include<Arduino.h>
class LED{
  private:
    unsigned char PIN;
    unsigned char Intensity;
  public:
    unsigned char Intensity;
    LED();
    LED(unsigned char P);
    ~LED();
    void SET(unsigned char P);
    void SETUP();
    void on();
    void on_pwm();
    void on_pwm(unsigned char I);
    void off();
    void BLINK(unsigned int btime);

  };
class LED_RGB{
private:
  unsigned char channel_red, channel_blue,channel_green;
  

public:
  unsigned char brightness_red, brightness_blue, brightness_green;
  
  LED_RGB();
  LED_RGB(unsigned char R, unsigned char B, unsigned char G);
  ~LED_RGB();

  void SET(unsigned char R, unsigned char B, unsigned char G);
  void SETUP();
  void Set_brightness(unsigned char BR, unsigned char BB, unsigned char BG);
  void off();
  void on();
  void on(unsigned char BR, unsigned char BB, unsigned char BG);
  void on_birghtness();
  void on_r();
  void on_b();
  void on_g();
  void off_r();
  void off_b();
  void off_g();
};
class Buttom{
    
    private: 
      unsigned char PIN; 
    public:
      Buttom();
      Buttom(unsigned char P);
      ~Buttom();
      void SET(unsigned char P);
      void SETUP();
      bool Read();
};
class Pot{
private:
  unsigned char analog_value;
public:
  Pot();
  Pot(unsigned char AX);
  ~Pot();

  int Read();
  unsigned char pwm_value();
};
#endif
