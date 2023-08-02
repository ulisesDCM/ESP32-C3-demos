#include "toogleLED.h"
#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"

#define LED_PIN         (GPIO_NUM_2)
#define LED_PIN_MASK    (1<<LED_PIN)

const gpio_config_t led_config = {
    .pin_bit_mask=LED_PIN_MASK,
    .mode=GPIO_MODE_OUTPUT,
    .pull_up_en=GPIO_PULLUP_ENABLE,
    .pull_down_en=GPIO_PULLDOWN_DISABLE,
    .intr_type=GPIO_INTR_DISABLE
};

void init_led(void){
    ESP_ERROR_CHECK(gpio_reset_pin(LED_PIN));
    ESP_ERROR_CHECK(gpio_config(&led_config));

}

void toogle_led(bool is_on){
    ESP_ERROR_CHECK(gpio_set_level(LED_PIN, (uint32_t) is_on));
}
