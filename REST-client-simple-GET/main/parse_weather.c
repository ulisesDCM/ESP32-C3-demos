#include <stdio.h>
#include <string.h>
#include "parse_weather.h"
#include "cJSON.h"  
#include "esp_log.h"
#include "esp_heap_caps.h"

#define LOG_TAG     ("parse_weather.c")

esp_err_t parse_weather(char *weatherStr){
    int dram=heap_caps_get_largest_free_block(MALLOC_CAP_8BIT);
    printf("***dram=%d\n",dram);

    cJSON *weatherJSON =  cJSON_Parse(weatherStr);
    if(weatherJSON == NULL){
        const char *err = cJSON_GetErrorPtr();
        if(err){
            ESP_LOGE(LOG_TAG, "Error parsing JSON before %s",err);
            return (esp_err_t) -1;
        }
    }

    cJSON *timezone = cJSON_GetObjectItemCaseSensitive(weatherJSON, "timezone");
    // cJSON *time = cJSON_GetObjectItemCaseSensitive(daily, "time");
    ESP_LOGI(LOG_TAG, "timezone: %s",timezone->valuestring);

    return ESP_OK;
}