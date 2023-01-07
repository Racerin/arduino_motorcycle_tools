/* Measure items using voltmeter circuit */

#include "Arduino.h"
#include "voltmeter.h"

Voltmeter::Voltmeter(int pin){
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void Voltmeter::calibrate(){}

int Voltmeter::read(){
    return analogRead(_pin);
}

void Voltmeter::setup(){
    Serial.begin(9600);
}

void Voltmeter::update(){
    /* 
        State what to do in update
     */
    // Get analog pin value
    _value = read();
    // print-out value
    Serial.println(_value);
}

