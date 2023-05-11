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

static void IRAM_ATTR gpio_isr_handler(void *args)
{
    ESP_LOGI(LOG_TAG, "Running GPIO ISR of pin %d",INPUT_INT_PIN);
}

void gpio_int_config(void)
{
    ESP_LOGI(LOG_TAG, "Initialize the %d pin to be an interrupt",INPUT_INT_PIN);
    
    gpio_install_isr_service(0);
    gpio_isr_handler_add(INPUT_INT_PIN, gpio_isr_handler, (void *) INPUT_INT_PIN);
}

