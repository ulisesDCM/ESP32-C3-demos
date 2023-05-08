#include "gpioOutput.h"

#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_TAG     ("gpioOutput.c")

const gpio_config_t led_config = {
    .intr_type=GPIO_INTR_DISABLE,
    .mode=GPIO_MODE_OUTPUT,
    .pin_bit_mask=LED_BIT_MASK,
    .pull_down_en=GPIO_PULLDOWN_DISABLE,
    .pull_up_en=GPIO_PULLUP_ENABLE
};

static void toogle_white_red_task(void *params)
{
    static int led_state = 0;
    while(1)
    {
        set_led_state(RED, led_state);
        set_led_state(WHITE, led_state);
        led_state = !led_state & 1;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

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

void led_toogle_create_task(void)
{
    xTaskCreate(&toogle_white_red_task, "red white toogle task", 1024*2, NULL, 2, NULL);
}