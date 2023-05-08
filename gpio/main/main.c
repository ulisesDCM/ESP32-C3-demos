#include <stdio.h>

#include "gpioOutput.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#define MAIN_LOG_TAG    ("main.c")

void app_main(void)
{
    gpio_output_config();
    int red_state = 0;

    while(1)
    {
        set_led_state(RED, red_state);
        set_led_state(WHITE, red_state);
        red_state = !red_state & 1;
        ESP_LOGI(MAIN_LOG_TAG, "Hello World!!!");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
