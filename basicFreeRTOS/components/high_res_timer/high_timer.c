#include <stdio.h>
#include "high_timer.h"

#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void timer_callback(void *args)
{
    //Do something every 50 us
}
void high_res_timer_example(void)
{
    const esp_timer_create_args_t esp_timer_create_args = {
        .callback = timer_callback,
        .name = "My timer"
    };

    esp_timer_handle_t esp_timer_handle;
    esp_timer_create(&esp_timer_create_args, &esp_timer_handle);
    esp_timer_start_periodic(esp_timer_handle, 50);

    while(1)
    {
        esp_timer_dump(stdout);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}