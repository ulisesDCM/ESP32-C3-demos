#include <stdio.h>

/*
    FreeRTOS guide for interation between 2 or more tasks.
        use TASK_NOTIFICATION if:
            I want to communicate directly to another task.
            I care about counting or sending simple data.

        use SEMAPHORE if:
            Someone needs to block or unblock a task. I don't
            care who.
        
        use MUTEX if:
            Only the task that blocks another task can unblock it.

        use QUEUE if:
            I need to pass data from one task to another.

        use EVENT_GROUP if:
            Multiple things need to happen before I unlock a task.
*/

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

    /* 
        To attach or create a task that will run in a second core if it is
        available is using the function xTaskCreatePinnedToCore as follow 

        xTaskCreatePinnedToCore(
                    &task2,
                    "Example Task 2",
                    2048,
                    NULL,
                    2,
                    NULL,
                    0);     //This parameter select the core which the task will be runnning.
    */

    while(1)
    {
        ESP_LOGI(ESP_LOG_TAG, "Running main loop");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
