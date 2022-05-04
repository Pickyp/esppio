#include "log_stuff.h"
#include "esp_log.h"
static const char *TAG = "log";
esp_err_t log_stuff()
{
    ESP_LOGI(TAG,"Example log");
    return ESP_OK;
}