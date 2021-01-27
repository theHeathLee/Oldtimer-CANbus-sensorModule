#ifndef MAX31855_h
#define MAX31855_h

#include "mbed.h"

class max31855
{
    SPI& spi;
    DigitalOut ncs;
    Timer pollTimer;
  public:
  
    max31855(SPI& _spi, PinName _ncs);
    void select();
    void deselect();
    void initialise(int setType=0);
    
    int ready();
    int faultCode;
    
    float chipTemp;
    float read_temp();
  private:
    PinName _CS_pin;
    PinName _SO_pin;
    PinName _SCK_pin;
    int _units;
    float _error;
};

#endif
