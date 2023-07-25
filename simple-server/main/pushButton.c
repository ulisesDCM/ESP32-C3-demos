#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pushButton.h"
#include "driver/gpio.h"
#include "esp_log.h"    
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#define LOG_TAG             ("pushbutton.c")
#define PUSH_BUTTON_PIN     (GPIO_NUM_3)
#define PUSH_BUTTON_MASK    (1<<PUSH_BUTTON_PIN)


static void IRAM_ATTR on_button_pushed(void *arg){
}

const gpio_config_t button_config = {
    .pin_bit_mask=PUSH_BUTTON_MASK,
    .mode=GPIO_MODE_INPUT,
    .pull_up_en=GPIO_PULLUP_ENABLE,
    .pull_down_en=GPIO_PULLDOWN_DISABLE,
    .intr_type=GPIO_INTR_ANYEDGE
};

void init_button(void){
    ESP_ERROR_CHECK(gpio_reset_pin(PUSH_BUTTON_PIN));
    ESP_ERROR_CHECK(gpio_config(&button_config));

    gpio_install_isr_service(0);
    gpio_isr_handler_add(PUSH_BUTTON_PIN, on_button_pushed, NULL);
}