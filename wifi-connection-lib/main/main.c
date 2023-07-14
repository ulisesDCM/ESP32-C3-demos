#include <stdio.h>
#include "connect.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#define MAIN_LOG_TAG        ("main.c")

void wifi_connect(void *params){
    esp_err_t err=wifi_connect_sta("IZZI-EC7D", "Taquitos9.",10000);
    if(err){
        ESP_LOGI(MAIN_LOG_TAG, "Failed to connect");
        vTaskDelete(NULL);
    }

    for(int i=5;i>0;i--){
        ESP_LOGI(MAIN_LOG_TAG, "Disconnecting in %d",i);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    wifi_disconnect();
    vTaskDelete(NULL);
}

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    wifi_init();
    xTaskCreate(wifi_connect, "wifi_connect", 1024*5, NULL, 5, NULL);

}
