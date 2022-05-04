#include "unity.h"
#include "log_stuff.h"
#include "stdbool.h"
void test_log(void)
{
    log_stuff();
}

void app_main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_log);
    UNITY_END();
}