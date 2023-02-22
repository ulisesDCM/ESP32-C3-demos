#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define MAIN_LOG_TAG    ("main.c")

// Outputs without interrupt.
#define GPIO2_OUTPUT_NINT_PIN    (2)
#define GPIO3_OUTPUT_NINT_PIN    (3)
#define GPIO2_3_MASK_BIT         ( (1<< GPIO2_OUTPUT_NINT_PIN) | (1<< GPIO3_OUTPUT_NINT_PIN) )

// Inputs without interrupt.
#define GPIO0_INPUT_NINT_PIN    (0)
#define GPIO1_INPUT_NINT_PIN    (1)
#define GPIO0_1_MASK_BIT        ( (1<<GPIO0_INPUT_NINT_PIN) | (1<<GPIO1_INPUT_NINT_PIN))

// Inputs with interrupt.
#define GPIO7_INPUT_INT_PIN     (7)
#define GPIO6_INPUT_INT_PIN     (6)
#define GPIO7_6_MASK_BIT        ( (1<<GPIO7_INPUT_INT_PIN) | (1<<GPIO6_INPUT_INT_PIN))


static const gpio_config_t gpios_config_list[] = 
{   
    // Outputs without interrupt.
    {
        .intr_type=GPIO_INTR_DISABLE,
        .mode=GPIO_MODE_OUTPUT,
        .pin_bit_mask=GPIO2_3_MASK_BIT,
        .pull_down_en=GPIO_PULLDOWN_DISABLE,
        .pull_up_en=GPIO_PULLUP_DISABLE
    },

    // Inputs without interrupt.
    {
        .intr_type=GPIO_INTR_DISABLE,
        .mode=GPIO_MODE_INPUT,
        .pin_bit_mask=GPIO0_1_MASK_BIT,
        .pull_down_en=GPIO_PULLDOWN_ENABLE,
        .pull_up_en=GPIO_PULLUP_DISABLE
    },

    // Inputs with interrupt.
    {
        .intr_type=GPIO_INTR_POSEDGE,
        .mode=GPIO_MODE_INPUT,
        .pin_bit_mask=GPIO7_6_MASK_BIT,
        .pull_down_en=GPIO_PULLDOWN_ENABLE,
        .pull_up_en=GPIO_PULLUP_DISABLE
    },
};


void app_main(void)
{
    gpio_config(&gpios_config_list[0]);

    while(1)
    {
        ESP_LOGI(MAIN_LOG_TAG, "Hello World!!!");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
