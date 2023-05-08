#include "gpioInput.h"

#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_TAG     ("gpioInput.c")

const gpio_config_t switch_conf = {
    .intr_type=GPIO_INTR_DISABLE,
    .mode=GPIO_MODE_INPUT,
    .pin_bit_mask=SWITCH_BIT_MASK,
    .pull_down_en=GPIO_PULLDOWN_ENABLE,
    .pull_up_en=GPIO_PULLUP_DISABLE
};

void input_switch_configure(void)
{
    gpio_config(&switch_conf);
}

int get_switch_state(eSWITCH sw)
{
    return gpio_get_level(sw);    
}

static void switch_task(void *params)
{
    while(1)
    {
        ESP_LOGI(LOG_TAG, "Switch 0 state: %d", get_switch_state(SWITCH0));
        ESP_LOGI(LOG_TAG, "Switch 1 state: %d", get_switch_state(SWITCH1));
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void create_switch_task(void)
{
    xTaskCreate(&switch_task, "switch 0 and 1 task", 1024*2, NULL, 3, NULL);
}