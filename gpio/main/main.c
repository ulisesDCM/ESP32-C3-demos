#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "gpioOutput.h"
#include "gpioInput.h"

#define MAIN_LOG_TAG    ("main.c")

void app_main(void)
{
    gpio_output_config();
    led_toogle_create_task();

    while(1)
    {
        ESP_LOGI(MAIN_LOG_TAG, "Hello World!!!");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
