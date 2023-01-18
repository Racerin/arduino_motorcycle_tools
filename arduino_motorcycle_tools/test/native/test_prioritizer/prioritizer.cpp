#include <unity.h>
#include <Prioritizer.h>

void setUp(void){}

void tearDown(void){}

void test_example()
{
    // Ignore the test this command is placed in.
    TEST_IGNORE_MESSAGE("This is the message to return when this test is ignored.");
    TEST_IGNORE();

    // Common assertions
    TEST_ASSERT_TRUE(1);
    TEST_ASSERT_EQUAL(1, 1);
}

void test_create_empty_priority(void)
{
    Priority prty = Priority();
    TEST_ASSERT_TRUE(prty.lvl > INT_MAX - 1);
    TEST_ASSERT_EQUAL(prty.max_dt, 0);
}

void test_create_common_priority()
{
    Priority prty = Priority();
}

int main()
{
    UNITY_BEGIN();

    if (TEST_PROJECT())
    {
        // Run unit tests
        RUN_TEST(test_create_empty_priority);
        RUN_TEST(test_create_common_priority);
    }

    // End unit tests
    UNITY_END();
    
    return 0;
}