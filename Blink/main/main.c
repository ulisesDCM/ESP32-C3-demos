#include <stdio.h>
#include "esp_log.h"

void app_main(void)
{
    //TAG
    esp_log_level_set("LOG", ESP_LOG_INFO);

    //Log messages.
    ESP_LOGE("LOG", "This is an error!!! ");
    ESP_LOGW("LOG", "This is a warning!!!");
    ESP_LOGI("LOG","This is an information!!");
    ESP_LOGD("LOG", "This is a debug message!!!");
    ESP_LOGV("LOG","This is a verbose!!!");

    int number = 0;
    ESP_LOGE("ERROR", "This is an error!!! %d",number++);
    ESP_LOGW("WARNING", "This is a warning!!! %d",number++);
    ESP_LOGI("INfO","This is an information!! %d",number++);
    ESP_LOGD("DEBUG", "This is a debug message!!! %d",number++);
    ESP_LOGV("VERBOSE","This is a verbose!!! %d",number++);
}
