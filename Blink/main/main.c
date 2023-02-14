#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_random.h"
#include "driver/gpio.h"

#define RANDOM "RANDOM"
#define LED_PIN (1ULL<<GPIO_NUM_8)


gpio_config_t led_conf = {};
int led_state = 0;

int dice_role()
{
    long int random = esp_random();
    int posNumber = abs(random);
    int diceNumber = posNumber%20;
    return diceNumber;
}

static void gpio_led_config(void)
{
    led_conf.intr_type = GPIO_INTR_DISABLE;
    led_conf.mode = GPIO_MODE_OUTPUT;
    led_conf.pin_bit_mask = LED_PIN;
    led_conf.pull_down_en = 0;
    led_conf.pull_up_en = 0;
    gpio_reset_pin(GPIO_NUM_8);
    gpio_config(&led_conf);
}

static void gpio_led_toogle(void)
{
    int led_curr_state = 0;
    gpio_set_level(GPIO_NUM_8, 1);
    led_curr_state =  gpio_get_level(GPIO_NUM_8);
   
    led_state = !led_state;
    ESP_LOGI("LOG", "THe value of led_state is %d",led_state);
    ESP_LOGI("LOG", "THe real value  of gpio8  is %d",led_curr_state);
}   

void app_main(void)
{
    printf("hello world!!\n");

    //Minimum TAG
    esp_log_level_set("LOG", ESP_LOG_INFO);
    //Log messages.
    ESP_LOGE("LOG", "This is an error!!! ");
    ESP_LOGW("LOG", "This is a warning!!!");
    ESP_LOGI("LOG","This is an information!!");
    ESP_LOGD("LOG", "This is a debug message!!!");
    ESP_LOGV("LOG","This is a verbose!!!");
    
    int number = 0;
    uint16_t loopCount = 0;
    ESP_LOGE("ERROR", "This is an error!!! %d",number++);
    ESP_LOGW("WARNING", "This is a warning!!! %d",number++);
    ESP_LOGI("INfO","This is an information!! %d",number++);
    ESP_LOGD("DEBUG", "This is a debug message!!! %d",number++);
    ESP_LOGV("VERBOSE","This is a verbose!!! %d",number++);

    
    //Init the GPIO pin to control the RGB LED.
    gpio_led_config();

    while (1)
    {
        ESP_LOGI("INF", "loopCount value is %d",loopCount++);
        ESP_LOGI(RANDOM, "The random number is %d",dice_role());

        //Toogle LED.
        gpio_led_toogle();
    
        //Main loop delay.
        vTaskDelay(1000/portTICK_PERIOD_MS);                    //1 second delay
    }
    
}