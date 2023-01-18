#include <unity.h>
#include <Arduino.h>
#include <Prioritizer.h>

void setUp(void){}

void tearDown(void){}

void test_some_embedded_function(void)
{
    // TEST_ASSERT_EQUAL(,);
}

void setup()
{
    /* 
    IDK what the following means.
    NOTE!!! Wait for >2 secs
    if board doesn't support software reset via Serial.DTR/RTS 
    */
    delay(2000);

    //    Do things for setup here

    // Start unit testing
    UNITY_BEGIN();
}

void loop(){
    // Any further configs?

    // Run tests
    RUN_TEST(test_some_embedded_function);

    // End unit testing
    UNITY_END();
}