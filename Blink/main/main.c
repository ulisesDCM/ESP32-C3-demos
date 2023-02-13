#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_random.h"
#include "driver/gpio.h"

#define RANDOM "RANDOM"
#define LED_PIN 8

int dice_role()
{
    long int random = esp_random();
    int posNumber = abs(random);
    int diceNumber = posNumber%20;
    return diceNumber;
}

void app_main(void)
{
    //Minimum TAG
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

    uint16_t loopCount = 0;
    
    //Init the GPIO pin to control the RGB LED.
    uint32_t ledState =0;
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1)
    {
        ESP_LOGI("INF", "loopCount value is %d",loopCount++);
        ESP_LOGI(RANDOM, "The random number is %d",dice_role());

        //Toogle LED.
        ledState = !ledState;
        gpio_set_level(LED_PIN, ledState); 
        ESP_LOGI("INF","ledState value is %ld",ledState);
    
        //Main loop delay.
        vTaskDelay(1000/portTICK_PERIOD_MS);                    //1 second delay
    }
    
}