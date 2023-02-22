#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#define LOG_TAG         "main.c"
#define PIN2_OUTPUT     2

static const gpio_config_t pin2Configuration = 
{
    .intr_type=GPIO_INTR_DISABLE,
    .mode=GPIO_MODE_OUTPUT,
    .pin_bit_mask=(1<<PIN2_OUTPUT),
    .pull_down_en=GPIO_PULLDOWN_DISABLE,
    .pull_up_en=GPIO_PULLUP_DISABLE
};

void pin2_config_method2(void)
{
    gpio_reset_pin(PIN2_OUTPUT);
    gpio_config(&pin2Configuration);
}

void pin2_config_method1(void)
{
    gpio_reset_pin(PIN2_OUTPUT);
    gpio_set_direction(PIN2_OUTPUT, GPIO_MODE_OUTPUT);
}

void pin2_toogle(void)
{
    static uint8_t pin2_state = 0;
    pin2_state = !pin2_state;
    gpio_set_level(PIN2_OUTPUT, pin2_state);
}

void app_main(void)
{
    // pin2_config_method1();
    pin2_config_method2();

    while (1)
    {
        pin2_toogle();
        ESP_LOGI(LOG_TAG, "Hello world!!!");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    
}
