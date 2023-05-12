#include "adc.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"

#define LOG_TAG     ("adc.c")

static void adc_read_task(void *params)
{
    int adc1_ch1_val = 0;

    while(1)
    {
        adc1_ch1_val = adc1_get_raw(ADC1_CHANNEL_1);
        ESP_LOGI(LOG_TAG, "ADC1 channel1 raw value is %d",adc1_ch1_val);

        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void init_adc(void)
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_1, ADC_ATTEN_DB_0);

    xTaskCreate(&adc_read_task, "ADC TASK", 1024*2, NULL, 2, NULL);
}