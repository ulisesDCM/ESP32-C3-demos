#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_TAG     ("main.c")

void app_main(void)
{
    while(1)
    {
        ESP_LOGI(LOG_TAG, "Hello world!!!");

        #ifdef CONFIG_MY_BOOL
            ESP_LOGI(LOG_TAG, "Custom menuconfig, CONFIG_MY_BOOL %d",CONFIG_MY_BOOL);
        #endif
        ESP_LOGI(LOG_TAG, "Custom menuconfig, CONFIG_MY_STRING %s",CONFIG_MY_STRING);
        ESP_LOGI(LOG_TAG, "Custom menuconfig, CONFIG_MY_INT %d",CONFIG_MY_INT);

        #ifdef CONFIG_OPTION_1
            ESP_LOGI(LOG_TAG, "Custom menuconfig, CONFIG_OPTION_1 %d",CONFIG_OPTION_1);
        #elif CONFIG_OPTION_2
            ESP_LOGI(LOG_TAG, "Custom menuconfig, CONFIG_OPTION_2 %d",CONFIG_OPTION_2);
        #elif CONFIG_OPTION_3
            ESP_LOGI(LOG_TAG, "Custom menuconfig, CONFIG_OPTION_3 %d",CONFIG_OPTION_3);
        #endif

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
