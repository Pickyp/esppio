#include "unity.h"
#include "sum.h"
#include "stdbool.h"
void test_sum(void)
{
    // ARRANGE
    int a = 1;
    int b = 2;
    // ACT
    int actual = sum(a, b);
    // ASSERT
    TEST_ASSERT_EQUAL(3, actual);
}

void test_sum_fail(void)
{
    TEST_ASSERT_EQUAL(true,false);
}