#include "connect.h"
#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_netif.h"
#include "esp_wifi.h"

#define CONNECT_LOG_TAG     ("connect.c")

void event_handler(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, 
                    void* event_data){
    switch (event_id)
    {
    case WIFI_EVENT_STA_START:
        ESP_LOGI(CONNECT_LOG_TAG, "connecting...");
        esp_wifi_connect();
        break;
    case WIFI_EVENT_STA_CONNECTED:
        ESP_LOGI(CONNECT_LOG_TAG, "connected...");
        break;

    case WIFI_EVENT_STA_DISCONNECTED:
        ESP_LOGI(CONNECT_LOG_TAG, "disconnected...");
        break;

    case IP_EVENT_STA_GOT_IP:
        ESP_LOGI(CONNECT_LOG_TAG, "got ip");
        break;
    
    default:
        break;
    }
}

void wifi_init(void){
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    wifi_init_config_t wifi_init_config = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&wifi_init_config));
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, event_handler, NULL));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));

}

esp_err_t wifi_connect_sta(const char *ssid, const char *pass, int timeout){

    return  ESP_OK; 
}

void wifi_connect_ap(const char *ssid, const char *pass){

}

void wifi_disconnect(void){

}
