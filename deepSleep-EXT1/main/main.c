#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"
#include "driver/rtc_io.h"

#define BUTTON_1  GPIO_NUM_10
#define BUTTON_2  GPIO_NUM_11

/* Use the RTC_DATA_ATTR to store a variable/data in 
a certaing part of the memory where is not deleted once the ESP32
goes to the deep sleep mode.  */

RTC_DATA_ATTR int timesWokenUp =0;  //<-- This variable won't be reseted 

void app_main(void)
{
    rtc_gpio_deinit(BUTTON_1);
    rtc_gpio_deinit(BUTTON_2);
    //Genral gpio function using the pin.
    
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON); 
    rtc_gpio_pullup_en(BUTTON_1);
    rtc_gpio_pulldown_dis(BUTTON_1);
    rtc_gpio_pullup_en(BUTTON_2);
    rtc_gpio_pulldown_dis(BUTTON_2);

    uint64_t buttons_mask = (1UL<<BUTTON_1) | (1UL<<BUTTON_2);
    esp_sleep_enable_ext1_wakeup(buttons_mask, ESP_EXT1_WAKEUP_ALL_LOW);
    printf("timesWokenUp = %d\n",timesWokenUp++);
    printf("going to deep sleep\n");

    esp_deep_sleep_start();

    printf("waking up\n");  // <--- The program resets before print this message...
    vTaskDelay(pdMS_TO_TICKS(1000));
}
