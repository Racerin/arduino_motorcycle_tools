#include <unity.h>
#include <Prioritizer.h>

void setUp(void) {}

void tearDown(void) {}

void test_example()
{
    // Ignore the test this command is placed in.
    TEST_IGNORE_MESSAGE("This is the message to return when this test is ignored.");
    TEST_IGNORE();

    // Common assertions
    TEST_ASSERT_TRUE(1);
    TEST_ASSERT_EQUAL(1, 1);
}

void test_FunctionPointer()
{
    FunctionPointer fptr = FunctionPointer();
}

void test_create_empty_priority(void)
{
    // Priority prty = Priority();
    Priority prty;
    TEST_ASSERT_TRUE(prty.lvl > INT_MAX - 1);
    TEST_ASSERT_EQUAL(prty.max_dt, 0);
}

void test_create_common_priority()
{
    // void * function = []() { int a = 1; };
    // void * function = []() {};
    FunctionPointer function = FunctionPointer();
    int level = 10;
    int dt = 100;
    int st = 1000;
    Priority prty = Priority(function, level, dt, st);

    // Tests
    TEST_ASSERT_EQUAL(prty.fptr, function);
    TEST_ASSERT_EQUAL(prty.lvl, level);
    TEST_ASSERT_EQUAL(prty.max_dt, dt);
    TEST_ASSERT_EQUAL(prty.start_time, st);
    
    // FOLLOWING LINE TO CHANGE
    TEST_ASSERT_NOT_NULL(function);
}

int main()
{
    UNITY_BEGIN();

    // Run unit tests
    RUN_TEST(test_example);
    RUN_TEST(test_FunctionPointer);
    RUN_TEST(test_create_empty_priority);
    RUN_TEST(test_create_common_priority);

    // End unit tests
    UNITY_END();

    return 0;
}