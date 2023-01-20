#include "arduino_motorcycle_tools.h"
#include "Arduino.h"


void setup()
{
    prtzr = Prioritizer();

    Serial.begin(115200);

    // Add priorities
    for (int i=0; i<10; i++)
    {
        int st = random(1000);
        int dt = random(200);
        int lvl = i % 3;0
        void (fptr*)() = []()
        {
            int ii = random();
            char buffer[40];
            sprintf(buffer, "Random int: %d.", ii);
            Serial.println(buffer);
        };

        prty = Priority(fptr, lvl, dt, st, true);
        prtzr.add_priority(prty);
    };

    // Run functions
    for (int i=0; i<5; i++)
    {
        prtzr.run_highest_priority();

        // Print functions here.
    }

}
    // Print final results

void loop(){};
