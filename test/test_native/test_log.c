#include "unity.h"
#include "log_stuff.h"
#include "stdbool.h"
#include "mock_esp_err.h"
#include "mock_ets_sys.h"
#include "mock_esp_log.h"

void setUp(void)
{
    esp_log_write_Ignore();
    esp_log_timestamp_IgnoreAndReturn(0);
}

void test_log_stuff(void)
{
    // ARRANGE
    int a = 1;
    int b = 2;
    // ACT
    esp_err_t actual = log_stuff();
    // ASSERT
    TEST_ASSERT_EQUAL(ESP_OK, actual);
}