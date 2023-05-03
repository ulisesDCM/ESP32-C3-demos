#include "tasks.h"
#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_TAG_TASKS  "tasks.c"

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

        FreeRTOS priority:
            High number --> High priority
            Low Number --> Low priority
*/

static void task_example1_task1(void *params)
{
    while(1)
    {
        ESP_LOGI(LOG_TAG_TASKS,"%s",(char *) params);
        vTaskDelay(pdMS_TO_TICKS(1000));  
    }
}

static void task_example1_task2(void *params)
{
    while (1)
    {
        ESP_LOGI(LOG_TAG_TASKS, "%s",(char *) params);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void task_example1(void)
{
    //Create task1
    xTaskCreate(&task_example1_task1,
                "task1",
                1024*2,
                "Running task1",
                2,
                NULL);

    //Create task2
    xTaskCreate(&task_example1_task2,
                "task2",
                1024*2,
                "Running task2",
                2,
                NULL);
}