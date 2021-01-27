/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "max31855.h"
#include <cstdint>
#include <cstdio>
#include <stdint.h>


CAN can(PA_11, PA_12);
SPI thermoSpi(PA_7, PA_6, PA_5);
max31855 max1(thermoSpi, PB_6);
//BufferedSerial pcSerial(USBTX, USBRX);
//#define MAXIMUM_BUFFER_SIZE        32
//static BufferedSerial serial_port(USBTX, USBRX, 9600);

// Blinking rate in milliseconds
#define BLINKING_RATE     1000ms

//void float2Bytes(uint8_t bytes_temp[4],float float_variable);
void float2Bytes(uint8_t bytes_temp[4],float float_variable);



int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    


    //Can Bus
    can.frequency(250000);
    CANMessage msg;
    msg.id = 0x100;
    msg.len = 4;
    msg.data[0] = 0xC0;
    msg.data[1] = 0xfE;
    msg.data[2] = 0xEE;
    float ctemperature = 0;
    uint32_t num = 666;
    uint8_t tempBytes[4];

    max1.initialise();

    while (true) {
        led = !led;
        if (max1.ready()==1){
        ctemperature = max1.read_temp()/100;
        float2Bytes(&tempBytes[0], ctemperature);
        msg.data[0] = tempBytes[0];
        msg.data[1] = tempBytes[1];
        msg.data[2] = tempBytes[2];
        msg.data[3] = tempBytes[3];
        }
        can.write(msg);
        ThisThread::sleep_for(BLINKING_RATE);
        printf("%d\n", (int)ctemperature);
    }
}


void float2Bytes(uint8_t bytes_temp[4],float float_variable){ 
  memcpy(bytes_temp, (unsigned char*) (&float_variable), 4);
}
