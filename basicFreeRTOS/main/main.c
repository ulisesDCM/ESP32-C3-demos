#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "tasks.h"
#include "notifications.h"
#include "mutex.h"
#include "semaphore.h"
#include "queue.h"
#include "event_groups.h"
#include "timer.h"

#define ESP_LOG_TAG     "main.c"

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


void app_main(void) 
{
    /* Uncomment just one of the following lines to run example. */

    // task_example1();     
    // tasks_notifications_example1();
    // tasks_notifications_example2();
    // mutex_example1();
    // semaphore_example1();
    // queue_example1();
    // event_groups_example1();
    rtos_timer_example1();
    ESP_LOGI(ESP_LOG_TAG, "Running main loop");        
    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}
