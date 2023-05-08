#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "gpioOutput.h"
#include "gpioInput.h"
#include "gpioInterrupt.h"

#define MAIN_LOG_TAG    ("main.c")

void app_main(void)
{
    //LED Output config.
    gpio_output_config();
    led_toogle_create_task();

    //Input switch config
    input_switch_configure();
    create_switch_task();

    //Configure interrupt
    gpio_int_config();

    while(1)
    {
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
