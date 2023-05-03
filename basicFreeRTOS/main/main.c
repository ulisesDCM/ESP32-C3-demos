#include <stdio.h>

#include "tasks.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define ESP_LOG_TAG     "main.c"

void app_main(void) 
{
    task_example1();
    while(1)
    {
        ESP_LOGI(ESP_LOG_TAG, "Running main loop");        
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}
