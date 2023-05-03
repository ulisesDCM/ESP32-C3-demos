#include "notifications.h"
#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_TAG_NOTIFICATIONS   ("notifications.c")

static TaskHandle_t receiveHandler = NULL;

static void sender(void *params)
{
    while(1)
    {
        xTaskNotifyGive(receiveHandler);
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}
    
static void receiver(void *params)
{
    while(1)
    {
        ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
        ESP_LOGI(LOG_TAG_NOTIFICATIONS, "recived notification");
    }
}

void tasks_notifications_example1(void)
{
    ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Creating tasks.");

    /* First create the task with the notification attached. */
    xTaskCreate(&receiver,"receiver task", 1024*2, NULL, 2, &receiveHandler);   
    xTaskCreate(&sender, "sender task", 1024*2, NULL, 2, NULL);
    
    ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Finished the tasks creation, getting back to main loop.");
}