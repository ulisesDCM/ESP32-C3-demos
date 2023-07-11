#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"

#define MAIN_LOG_TAG    ("main.c")
#define MAX_APs         (20)

void wifiInit(){
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    
    wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();

    ESP_ERROR_CHECK(esp_wifi_init(&wifi_config));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
}

static char *getAuthModeName(wifi_auth_mode_t auth_mode)
{
  char *names[] = {"OPEN", "WEP", "WPA PSK", "WPA2 PSK", "WPA WPA2 PSK", "MAX"};
  return names[auth_mode];
}

void app_main(void)
{
    wifiInit();
    /* 0 --> looking for everything */
    wifi_scan_config_t scan_config = {
        .ssid = 0,
        .bssid = 0,
        .channel = 0,
        .show_hidden=true
    };

    ESP_ERROR_CHECK(esp_wifi_scan_start(&scan_config, true));
    
    wifi_ap_record_t wifi_records[MAX_APs];
    uint16_t max_records = MAX_APs;

    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&max_records, &wifi_records));

    printf("Found %d access points:\n", max_records);
    printf("\n");
    printf("               SSID              | Channel | RSSI |   Auth Mode \n");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < max_records; i++)
        printf("%32s | %7d | %4d | %12s\n", (char *)wifi_records[i].ssid, 
        wifi_records[i].primary, wifi_records[i].rssi, 
        getAuthModeName(wifi_records[i].authmode));

    printf("----------------------------------------------------------------\n");
}
