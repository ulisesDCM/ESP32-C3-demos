#include <stdio.h>
#include "queue.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define LOG_TAG_QUEUE ("queue.c")

QueueHandle_t queue;

static void queue_task1(void *params)
{
    int count = 0;

    while(1)
    {
        count++;
        ESP_LOGI(LOG_TAG_QUEUE, "Running queue task1.");
        long ok = xQueueSend(queue, &count, pdMS_TO_TICKS(1000));
        if(ok)
        {
            printf("Added element to queue.\n");
        }
        else
        {
            printf("Failed to add element to queue\n");
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void queue_task2(void *params)
{
    while(1)
    {
        int rxInt; 
        int  ok = xQueueReceive(queue, &rxInt, pdMS_TO_TICKS(5000));
        ESP_LOGI(LOG_TAG_QUEUE, "Running queue task2.");
        if(ok)
        {
            printf("The digit in the queue is: %d\n",rxInt);
        }
        else
        {
            printf("Failed to get element to queue\n");
        }
    }
}


void queue_example1(void)
{
    ESP_LOGI(LOG_TAG_QUEUE, "Running queue example 1, creating tasks.");
    
    queue = xQueueCreate(10, sizeof(int));

    xTaskCreate(&queue_task1, "queue task1", 1024*2, NULL, 2, NULL);
    xTaskCreate(&queue_task2, "queue task2", 1024*2, NULL, 2, NULL);

    ESP_LOGI(LOG_TAG_QUEUE, "Finish to create tasks.");

}