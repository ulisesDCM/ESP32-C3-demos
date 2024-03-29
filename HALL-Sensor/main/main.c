#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#define LOG_TAG     ("main.c")

uint32_t hall_sens_read();

void app_main(void)
{
    while (1)
    {
        ESP_LOGI(LOG_TAG, "Hall sen: %ld",hall_sens_read());
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }   
}
