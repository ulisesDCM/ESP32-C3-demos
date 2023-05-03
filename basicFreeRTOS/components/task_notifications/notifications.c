#include "notifications.h"
#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_TAG_NOTIFICATIONS   ("notifications.c")

static TaskHandle_t receiveHandler = NULL;
static TaskHandle_t receiveHandler2 = NULL;

static void sender(void *params)
{
    while(1)
    {
        xTaskNotifyGive(receiveHandler);        //Notification 5.
        xTaskNotifyGive(receiveHandler);        //Notification 4
        xTaskNotifyGive(receiveHandler);        //Notification 3
        xTaskNotifyGive(receiveHandler);        //Notification 2
        xTaskNotifyGive(receiveHandler);        //Notification 1
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}
    
static void receiver(void *params)
{
    uint32_t notification_number = 0;

    while(1)
    {
        notification_number =  ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        ESP_LOGI(LOG_TAG_NOTIFICATIONS, "recived notification");
        ESP_LOGI(LOG_TAG_NOTIFICATIONS, "notification number: %ld",notification_number);
    }
}

void tasks_notifications_example1(void)
{
    ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Running task notifications example 1. ");
    ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Creating tasks.");

    /* First create the task with the notification attached. */
    xTaskCreate(&receiver,"receiver task", 1024*2, NULL, 2, &receiveHandler);   
    xTaskCreate(&sender, "sender task", 1024*2, NULL, 2, NULL);
    
    ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Finished the tasks creation, getting back to main loop.");
}

static void sender2(void *params)
{
    while(1)
    {
        ESP_LOGI(LOG_TAG_NOTIFICATIONS,"sender 2 is running");
        xTaskNotify(receiveHandler2, (1<<0),eSetValueWithoutOverwrite);
        vTaskDelay(pdMS_TO_TICKS(1000));

        xTaskNotify(receiveHandler2, (1<<1),eSetValueWithoutOverwrite);
        vTaskDelay(pdMS_TO_TICKS(1000));
        
        xTaskNotify(receiveHandler2, (1<<2),eSetValueWithoutOverwrite);
        vTaskDelay(pdMS_TO_TICKS(1000));
        
        xTaskNotify(receiveHandler2, (1<<3),eSetValueWithoutOverwrite);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void receiver2(void *params)
{
    uint32_t sender2_state = 0;

    while(1)
    {
        ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Receiver 2 is waiting for notification...");
        xTaskNotifyWait(0, 0, &sender2_state, portMAX_DELAY );
        ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Receiver 2 state received: %ld", sender2_state);
    }
}


void tasks_notifications_example2(void)
{
    ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Running task notifications example 2. ");
    ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Creating tasks. ");
    
    xTaskCreate(&receiver2, "receiver 2", 1024*2, NULL, 2, &receiveHandler2);
    xTaskCreate(&sender2, "sender 2", 1024*2, NULL, 2, NULL);

    ESP_LOGI(LOG_TAG_NOTIFICATIONS, "Finished the tasks creation, getting back to main loop.");
}