#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"

/* Use the RTC_DATA_ATTR to store a variable/data in 
a certaing part of the memory where is not deleted once the ESP32
goes to the deep sleep mode.  */

RTC_DATA_ATTR int timesWokenUp =0;  //<-- This variable won't be reseted 

void app_main(void)
{
    esp_sleep_enable_timer_wakeup(5*1000000);
    printf("timesWokenUp = %d\n",timesWokenUp++);
    printf("going to deep sleep\n");
    esp_deep_sleep_start();

    printf("waking up\n");  // <--- The program resets before print this message...
    vTaskDelay(pdMS_TO_TICKS(1000));
}
