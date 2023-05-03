#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "tasks.h"
#include "notifications.h"
#include "mutex.h"

#define ESP_LOG_TAG     "main.c"

void app_main(void) 
{
    /* Uncomment just one of the following lines to run example. */
    // task_example1();     
    // tasks_notifications_example1();
    // tasks_notifications_example2();
    mutex_example1();
    
    ESP_LOGI(ESP_LOG_TAG, "Running main loop");        
    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}
