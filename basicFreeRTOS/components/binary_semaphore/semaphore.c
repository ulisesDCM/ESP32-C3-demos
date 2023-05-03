#include <stdio.h>
#include "semaphore.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#define LOG_TAG_SEMAPHORE   ("semaphore.c")

static void semaphore_task1(void *params)
{
    while(1)
    {
        ESP_LOGI(LOG_TAG_SEMAPHORE, "Running semaphore task1.");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void semaphore_task2(void *params)
{
    while(1)
    {
        ESP_LOGI(LOG_TAG_SEMAPHORE, "Running semaphore task2.");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void semaphore_example1(void)
{
    ESP_LOGI(LOG_TAG_SEMAPHORE, "Running semaphore example 1, creating tasks.");
    xTaskCreate(&semaphore_task1, "semaphore task1", 1024*2, NULL, 2, NULL);
    xTaskCreate(&semaphore_task2, "semaphore task2", 1024*2, NULL, 2, NULL);
    ESP_LOGI(LOG_TAG_SEMAPHORE, "Finish to create tasks.");

}