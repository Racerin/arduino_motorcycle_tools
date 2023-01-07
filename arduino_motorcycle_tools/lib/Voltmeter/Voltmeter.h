/* 
    voltmeter.h - Library for measuring voltage using Arduino and circuit
    Created by Darnell Baird, January 7th, 2023.
    Released into the public domain.
 */

#ifndef Voltmeter_h
#define Voltmeter_h

#include "Arduino.h"

class Voltmeter
{
    public:
        Voltmeter(int pin);
        void calibrate();
        int read();
        void setup();
        void update();
    private:
        int _pin;
        int _value;
};

#endif