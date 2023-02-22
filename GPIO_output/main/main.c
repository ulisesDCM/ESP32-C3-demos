#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#define LOG_TAG         "main.c"
#define PIN2_OUTPUT     2

void app_main(void)
{
    uint8_t pin2_state = 0;

    gpio_reset_pin(PIN2_OUTPUT);
    gpio_set_direction(PIN2_OUTPUT, GPIO_MODE_OUTPUT);
    while (1)
    {

        gpio_set_level(PIN2_OUTPUT, pin2_state);
        ESP_LOGI(LOG_TAG, "Hello world!!!");
        vTaskDelay(1000/portTICK_PERIOD_MS);
        pin2_state = !pin2_state;
    }
    
}
