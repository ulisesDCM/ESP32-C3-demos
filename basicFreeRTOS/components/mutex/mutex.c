#include "mutex.h"

#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#define LOG_TAG_MUTEX       ("mutex.c")

SemaphoreHandle_t mutexBus;

void writeToBus(char *message)
{
    printf(message);
}


static void task_mutex1(void *params)
{

    while(1)
    {
        ESP_LOGI(LOG_TAG_MUTEX, "Running task mutex 1.");
      
        if( xSemaphoreTake(mutexBus, pdMS_TO_TICKS(1000)))
        {
            //The bus is available so it will write the temperature. 
            writeToBus("temerature is 25c.\n");
            xSemaphoreGive(mutexBus);   //Free the mutex semaphore flag.
        }
        else
        {
            //The bus is not avaiable for some reason.
            ESP_LOGI(LOG_TAG_MUTEX, "Writing temperature timeout.");
        }
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

static void task_mutex2(void *params)
{

    while(1)
    {
        ESP_LOGI(LOG_TAG_MUTEX, "Running task mutex 2.");
        if(xSemaphoreTake(mutexBus, pdMS_TO_TICKS(1000)))
        {
            writeToBus("humidity is 50\n");
            xSemaphoreGive(mutexBus);   //Free the mutex semaphore flag.
        }
        else
        {
            ESP_LOGI(LOG_TAG_MUTEX, "Writing humidity timeout.");
        }
        vTaskDelay(2000/portTICK_PERIOD_MS);
    }
}

void mutex_example1(void)
{
    ESP_LOGI(LOG_TAG_MUTEX, "Running mutex example 1, creating tasks.");

    mutexBus = xSemaphoreCreateMutex();

    xTaskCreate(&task_mutex1, "task mutex 1", 1024*2, NULL, 2, NULL);
    xTaskCreate(&task_mutex2, "task mutex 1", 1024*2, NULL, 2, NULL);

    ESP_LOGI(LOG_TAG_MUTEX, "Finished to create tasks exit from mutex example 1.");

}