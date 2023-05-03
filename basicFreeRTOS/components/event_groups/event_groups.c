#include <stdio.h>
#include "event_groups.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#define LOG_TAG_GROUPS  ("event_groups.c")

static void groups_task1(void *params)
{
    while(1)
    {
        ESP_LOGI(LOG_TAG_GROUPS, "Running groups task1");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void groups_task2(void *params)
{
    while(1)
    {
        ESP_LOGI(LOG_TAG_GROUPS, "Running groups task2");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void event_groups_example1(void)
{
    ESP_LOGI(LOG_TAG_GROUPS, "Running event groups example 1, creating tasks");
    xTaskCreate(&groups_task1, "task group 1", 1024*2, NULL, 2, NULL);
    xTaskCreate(&groups_task2, "task group 2", 1024*2, NULL, 2, NULL);

    ESP_LOGI(LOG_TAG_GROUPS, "Finish to create tasks, exiting function.");

}