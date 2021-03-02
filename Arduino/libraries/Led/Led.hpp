#ifndef LED_HPP
#define LED_HPP
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
    void led_setup();
    void set_intensity(unsigned char I);
    void Led_ON();
    void Led_off();
    void Led_blink(unsigned int btime);

  };

#endif
