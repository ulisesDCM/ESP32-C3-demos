#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "tasks.h"
#include "notifications.h"


#define ESP_LOG_TAG     "main.c"

void app_main(void) 
{
    // task_example1();     //uncomment this line to run the task example
    tasks_notifications_example1(); //uncomment this line to run the task notification example.

    ESP_LOGI(ESP_LOG_TAG, "Running main loop");        

    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}
