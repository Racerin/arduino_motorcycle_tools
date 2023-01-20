/* 
    Prioritizer.h - Library for actioning functions of higher priority
        (lower level) first. Priority has a start time and is sheduled based on
		history of duration, start time, and rank.
		Aim is to make it function faster than FreeRTOS asit has a lesser
		functionality.
    Created by Darnell Baird, January 12th, 2023.
    Released into the public domain.
 */

#ifndef Prioritizer_h
#define Prioritizer_h

#include "limits.h"


// typedef void(*FunctionPointer)();
// Alias
using FunctionPointer = void(*)();


class Priority{
	private:
		bool to_loop=false;
	public:
		FunctionPointer fptr;	// Pointer of function to call when priority to take action
		int lvl=INT_MAX;		// Priority with lower level is given leeway over others given there isn't enough time for next priority to execute.
		int max_dt;				// The maximum possible time needed to run the function
		int start_time;					// The time until the next function activation.
		int late_tolerance=0;	// runs the job even though it may start late once within variable's time
		Priority();
		// Priority(FunctionPointer fptr, int level, int maximum_dt=0, int start_time=0, bool loop);
		Priority(void * fptr, int level, int maximum_dt=0, int start_time=0, bool loop);
		int end_time();
		Priority higher_priority(Priority other);
};


class Prioritizer
{
    public:
		const static int N_PRIORITY = 10;	// This is the length limit of how many functions to add for now. Increase at your own discression (memory limit)
        Prioritizer();
		long get_time();
		void wait(int duration);
		int add_priority(Priority * prty);
        void timed_function(FunctionPointer function_pointer);
		int run_highest_priority();
        void loop();
        int time_factor = 2;
		volatile bool do_loop=false;
    private:
		int _start_time;			// Start time
		int _end_time;				// End time
		int _delta_process_time;	// Time taken to find priority
		int _delta_time_until_function;	// Time taken to find priority
        int _delta_time_priority;			// Delta time
        int priority_counter = 0;
        Priority _priorities[N_PRIORITY];
};

#endif