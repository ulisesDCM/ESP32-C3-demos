#include "gpioOutput.h"

#include "esp_log.h"
#include "driver/gpio.h"

#define LOG_TAG     ("gpioOutput.c")

const gpio_config_t led_config = {
    .intr_type=GPIO_INTR_DISABLE,
    .mode=GPIO_MODE_OUTPUT,
    .pin_bit_mask=LED_BIT_MASK,
    .pull_down_en=GPIO_PULLDOWN_DISABLE,
    .pull_up_en=GPIO_PULLUP_ENABLE
};

void gpio_output_config(void)
{
    ESP_LOGI(LOG_TAG, "Configuring all LED GPIO output ");
    gpio_reset_pin(LED_RED_GPIO_PIN);
    gpio_reset_pin(LED_WHITE_GPIO_PIN);
    gpio_config(&led_config);
}

void set_led_state(eLED led, int state)
{
    gpio_set_level(led, state);
}

