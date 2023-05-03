#include <stdio.h>
#include "timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "esp_system.h"
#include "esp_timer.h"

static void on_timer(TimerHandle_t  xTimer)
{
    printf("time is %lld\n",esp_timer_get_time()/1000);
}

void rtos_timer_example1(void)
{
    printf("app started at %lld \n",esp_timer_get_time()/1000);
    TimerHandle_t xTimer = xTimerCreate("my timer", pdMS_TO_TICKS(1000), true, NULL, on_timer);
    xTimerStart(xTimer, 0);
}