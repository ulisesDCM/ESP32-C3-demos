#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "gpioOutput.h"
#include "gpioInput.h"

#define MAIN_LOG_TAG    ("main.c")

void app_main(void)
{
    //LED Output config.
    gpio_output_config();
    led_toogle_create_task();

    //Input switch config
    input_switch_configure();

    while(1)
    {
        ESP_LOGI(MAIN_LOG_TAG, "Switch 0 state: %d",get_switch_state(SWITCH0));
        ESP_LOGI(MAIN_LOG_TAG, "Switch 1 state: %d",get_switch_state(SWITCH1));
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
