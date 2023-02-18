#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define ESP_LOG_TAG     "main.c"

void task1(void)
{
    while(1)
    {
        ESP_LOGI(ESP_LOG_TAG,"Running Task 1");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void task2(void)
{
    while (1)
    {
        ESP_LOGI(ESP_LOG_TAG, "Running Task 2");
        vTaskDelay(pdMS_TO_TICKS(700));
    }
    
}

void app_main(void) 
{
    // Creating task 1.
    xTaskCreate(&task1,
                "Example Task 1",
                2048,
                NULL,
                2,
                NULL);
    
    // Creating task 2.
    xTaskCreate(&task2,
                "Example Task 2",
                2048,
                NULL,
                2,
                NULL);

    while(1)
    {
        ESP_LOGI(ESP_LOG_TAG, "Running main loop");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
