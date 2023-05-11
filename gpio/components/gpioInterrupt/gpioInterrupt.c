#include "gpioInterrupt.h"

#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_TAG     ("gpioInterrupt.c")

const gpio_config_t int_config = {
    .pin_bit_mask=INPUT_INT_BIT_MASK,
    .mode=GPIO_MODE_INPUT,
    .pull_up_en=GPIO_PULLUP_DISABLE,
    .pull_down_en=GPIO_PULLDOWN_ENABLE,
    .intr_type=GPIO_INTR_POSEDGE
};

void gpio_int_config(void)
{
    ESP_LOGI(LOG_TAG, "Initialize the %d pin to be an interrupt",INPUT_INT_PIN);
    
}

