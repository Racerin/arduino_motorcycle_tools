 
#include "Arduino.h"
#include "Prioritizer.h"


Priority::Priority(FunctionPointer function_pointer, int level, int maximum_dt, int start_time) \
: fptr(), lvl(level), max_dt(maximum_dt), start_time(start_time) {};
// Initializer List - https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/

int Priority::end_time()
{
    // Returns the estimated time for the function to end
    return start_time + max_dt;
}

Priority Priority::higher_priority(Priority other)
{
    // If this priority has enough time to execute code, it is the better priority
    if (this->end_time() < other.start_time) { return *this; }
    // If the other priority has enough time to execute code, it is the better priority
    if (other.end_time() < this->start_time) { return *this; }
    // If this priority doesn't have enough time but is a higher priority (lower level), it is the higher priority
    // Otherwise, whichever priority has the higher rank (lower level) is given priority
    return this->lvl < other.lvl ? *this : other;
};

long Prioritizer::get_time(){
    // Return time according to system implemented eg. int Arduino>millis()
   return millis();
};

void Prioritizer::wait(int duration){
    // Sleep/wait for period of time
    delay(duration);
}

int Prioritizer::add_priority_function(FunctionPointer function_pointer, int level, int start_time)
{
    if (priority_counter < Prioritizer::N_PRIORITY){
        Priority new_priority(function_pointer, level, 0, start_time);
        _priorities[priority_counter] = new_priority;
        priority_counter ++;
    }
    else {return -1;}
    return 0;
}

int Prioritizer::run_highest_priority()
{
    /* Decide and run the next priority/function scheduled. */
    // Time checking
    _start_time = get_time();
    // Pick highest priority
    Priority best_priority;
    for (int i=0; i<priority_counter; i++){
        if (i==0){
            // Choose the only priority as the best
            if (priority_counter>0){ best_priority = _priorities[0]; }
            // If there are no priorities to choose from, exit function
            return -1;
        };
        // Otherwise, comapre and find the best priority
        best_priority = best_priority.higher_priority(_priorities[i]);
    };
    // Run/Execute function of highest priority at given time
    _end_time = get_time();
    _delta_process_time = _start_time - _end_time;
    _delta_time_until_function = best_priority.start_time - _delta_process_time; // [Temporary]. Estimated time delta until function runs
    _start_time = get_time();
    if (_delta_time_until_function > 0) { wait(_delta_time_until_function); } // Wait a bit until time to run the function at the right time
    best_priority.fptr();
    // Get time delta of function to run.
    _end_time = get_time();
    _delta_time_priority = _start_time - _end_time;
    // Set new delta time (if new record high)
    if (best_priority.max_dt > _delta_time_priority) { best_priority.max_dt = _delta_time_priority*time_factor; }
}

void Prioritizer::loop()
{
    do_loop = true;
    while(do_loop)
    {
        run_highest_priority();
    }
    /* 
    Run the priorities/functions in the prioritizer
    constantly.
    */
}