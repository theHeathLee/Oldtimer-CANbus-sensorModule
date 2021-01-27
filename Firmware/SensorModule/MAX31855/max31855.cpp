
#include <mbed.h>
#include "max31855.h"

max31855::max31855(SPI& _spi, PinName _ncs) : spi(_spi), ncs(_ncs) {

}

float max31855::read_temp() {
    short value = 0;
    float temp = 0;
    
    //Variables to hold probe temperature
    uint8_t tempProbeHigh=0;
    uint8_t tempProbeLow=0;
    
    //Variables to hold chip temperature and device status
    uint8_t tempChipHigh=0;
    uint8_t tempChipLow=0;
    
    if (pollTimer.read_ms() > 250){
        //Set CS to initiate transfer and stop conversion
        select();
    
        //Read in Probe tempeature
        tempProbeHigh = spi.write(0);
        tempProbeLow = spi.write(0);
        
        //Get the chip temperature and the fault data
        tempChipHigh = spi.write(0);
        tempChipLow = spi.write(0);
        
        //Set the chip temperature    
        chipTemp = (tempChipHigh<<4 | tempChipLow>>4)*0.25;
        
        //Set CS to stop transfer and restart conversion
        deselect(); 
        
        //Check for a fault (last bit of transfer is fault bit)
        if ((tempProbeLow & 1)==1){
            //Chip reports a fault, extract fault from Chip Temperature data
            int faultType = (tempChipLow & 7);
            
            faultCode=faultType;
            
            return 2000+faultType;
            /*if (faultType==1){
                //Open circuit (no TC)
                return 2000 + faultType;
            }else if (faultType==2){
                //Short to GND
                return 2000 + faultType;
            }else if (faultType==4){
                //Short to VCC               
                return 0.4;
            }else{
                return 0.5;
            }*/
        }else{
            //Integer value of temperature
            value = (tempProbeHigh<< 6 | tempProbeLow>>2);
    
            //Get actual temperature (last 2 bits of integer are decimal 0.5 and 0.25)
            temp = (value*0.25); // Multiply the value by 0.25 to get temp in C or
                             //  * (9.0/5.0)) + 32.0;   // Convert value to F (ensure proper floats!)
                             
            return temp;
        }
    }else{
        //Chip not ready for reading
        return -1;
    }
}

void max31855::select() {
    //Set CS low to start transmission (interrupts conversion)
    ncs = 0;
}

void max31855::deselect() {
    //Set CS high to stop transmission (restarts conversion)
    ncs = 1;
    //Reset conversion timer
    pollTimer.reset();
}

void max31855::initialise(int setType) {
    //Start the conversion timer
    pollTimer.start();
    faultCode=0;
}

int max31855::ready() {
    //Check to see if conversion is complete
    if (pollTimer.read_ms() > 250) {
        //Conversion complete
        return 1;
    }else{
        //Conversion incomplete
        return 0;
    }
}