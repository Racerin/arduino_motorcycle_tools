/* 
    Prioritizer.h - Library for actioning functions of higher priority
        (lower level) first.
    Created by Darnell Baird, January 12th, 2023.
    Released into the public domain.
 */

#ifndef Prioritizer_h
#define Prioritizer_h

#include "Arduino.h"
// #include <Arduino>

class Prioritizer
{
    public:
        Prioritizer();
        void add_priority_function(void (*func)(), int level);
        void add_priority_function(void (*func)(), int level, int def_time);
        void timed_function(void (*func)());
        void loop();
        int time_factor = 2;
    private:
        int _dt;
        // c++ array of function pointers
        void (* _arr_func [])() = {};
        int n_arr_func = 0;
}

#endif