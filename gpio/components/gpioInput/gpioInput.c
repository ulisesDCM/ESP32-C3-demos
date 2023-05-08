#include "gpioInput.h"

#include "esp_log.h"
#include "driver/gpio.h"

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
