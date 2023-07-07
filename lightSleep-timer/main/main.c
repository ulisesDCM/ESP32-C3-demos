#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"
#include "esp_log.h"
#include "esp_timer.h"
// #include "esp32/rom/uart.h"

void app_main(void)
{
    esp_sleep_enable_timer_wakeup(5*1000000);
    printf("going for a nap\n");
    vTaskDelay(pdMS_TO_TICKS(100));  //Just to wait until printf send the message to the console.

    int64_t before = esp_timer_get_time();
    esp_light_sleep_start();
    int64_t after = esp_timer_get_time();

    printf("napped for %lld\n",(after-before)/1000);
}
