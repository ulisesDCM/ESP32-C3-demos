#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "adc.h"

#define LOG_TAG ("main.c")

void app_main(void)
{
    init_adc();
    
    while (1)
    {
        ESP_LOGI(LOG_TAG, "HelloWorld!!!");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
