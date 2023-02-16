#include "myGPIO.h"

#include "driver/gpio.h"
#include "esp_log.h"

#define LOG_TAG_MYGPIO  "myGPIO.c"

void test_my_gpio(void)
{
    ESP_LOGI(LOG_TAG_MYGPIO, "running the test_my_gpio function.");
    gpio_config_t myGPIOConfig;     //Just to test the GPIO driver include.
}