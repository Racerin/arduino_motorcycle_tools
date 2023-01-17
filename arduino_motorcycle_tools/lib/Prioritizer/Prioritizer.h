/* 
    Prioritizer.h - Library for actioning functions of higher priority
        (lower level) first.
    Created by Darnell Baird, January 12th, 2023.
    Released into the public domain.
 */

#ifndef Prioritizer_h
#define Prioritizer_h

#define INT_MAX 32767	// This value was obtained from https://learn.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170


typedef void(*FunctionPointer)();


class Priority{
	private:
	public:
		FunctionPointer fptr;	// Pointer of function to call when priority to take action
		int lvl=INT_MAX;		// Priority with lower level is given leeway over others given there isn't enough time for next priority to execute.
		int max_dt;				// The maximum possible time needed to run the function
		int start_time;					// The time until the next function activation.
		Priority();
		Priority(FunctionPointer fptr, int level, int maximum_dt=0, int start_time=0);
		// Priority(FunctionPointer fptr, int level, int maximum_dt=0, int start_time=0);
		int end_time();
		Priority higher_priority(Priority other);
};


class Prioritizer
{
    public:
		const static N_PRIORITY = 10;	// This is the length limit of how many functions to add for now. Increase at your own discression (memory limit)
        Prioritizer();
		long get_time();
		void wait(int duration);
        int add_priority_function(FunctionPointer function_pointer, int level, int start_time);
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