#include <stdio.h>
#include "event_groups.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"

#define LOG_TAG_GROUPS  ("event_groups.c")

EventGroupHandle_t evtGroup;

const int goTask1 = BIT0;   // (1<<0)
const int goTask2 = BIT1;   // (1<<1)

static void groups_task1(void *params)
{
    while(1)
    {
        xEventGroupSetBits(evtGroup, goTask1);
        ESP_LOGI(LOG_TAG_GROUPS, "Running groups task1");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

static void groups_task2(void *params)
{
    while(1)
    {
        xEventGroupSetBits(evtGroup, goTask2);
        ESP_LOGI(LOG_TAG_GROUPS, "Running groups task2");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

static void groups_task3(void *params)
{
    while(1)
    {
        xEventGroupWaitBits(evtGroup, (goTask1 | goTask2), true, true, portMAX_DELAY);
        ESP_LOGI(LOG_TAG_GROUPS, "Running groups task3");
        ESP_LOGI(LOG_TAG_GROUPS, "Task 1 and task2 terminate their execution.");
    }
}

void event_groups_example1(void)
{
    ESP_LOGI(LOG_TAG_GROUPS, "Running event groups example 1, creating tasks");

    evtGroup = xEventGroupCreate();

    xTaskCreate(&groups_task1, "task group 1", 1024*2, NULL, 2, NULL);
    xTaskCreate(&groups_task2, "task group 2", 1024*2, NULL, 2, NULL);
    xTaskCreate(&groups_task3, "task group 3", 1024*2, NULL, 2, NULL);

    ESP_LOGI(LOG_TAG_GROUPS, "Finish to create tasks, exiting function.");

}