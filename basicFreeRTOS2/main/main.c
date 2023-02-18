#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define ESP_LOG_TAG     "main.c"

void app_main(void)
{

    while(1)
    {
        ESP_LOGI(ESP_LOG_TAG, "hello world!!!");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
