#include "mutex.h"

#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_TAG_MUTEX       ("mutex.c")

void mutex_example1(void)
{
    ESP_LOGI(LOG_TAG_MUTEX, "Running mutex example 1.");
    
}