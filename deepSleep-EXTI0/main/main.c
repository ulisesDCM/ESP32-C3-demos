#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"
#include "driver/rtc_io.h"

#define BUTTON  GPIO_NUM_10

/* Use the RTC_DATA_ATTR to store a variable/data in 
a certaing part of the memory where is not deleted once the ESP32
goes to the deep sleep mode.  */

RTC_DATA_ATTR int timesWokenUp =0;  //<-- This variable won't be reseted 

void app_main(void)
{
    rtc_gpio_deinit(BUTTON);
    //Genral gpio function using the pin.
    
    rtc_gpio_pullup_en(BUTTON);
    rtc_gpio_pulldown_dis(BUTTON);
    esp_sleep_enable_ext0_wakeup(BUTTON,0);
    printf("timesWokenUp = %d\n",timesWokenUp++);
    printf("going to deep sleep\n");

    esp_deep_sleep_start();

    printf("waking up\n");  // <--- The program resets before print this message...
    vTaskDelay(pdMS_TO_TICKS(1000));
}
