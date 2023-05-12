#include "pwm.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_err.h"

void init_pwm_led(void)
{
    ledc_timer_config_t timer_conf = {
        .speed_mode=LEDC_LOW_SPEED_MODE,
        .duty_resolution=LEDC_TIMER_10_BIT,
        .timer_num=LEDC_TIMER_0,
        .freq_hz=5000,
        .clk_cfg=LEDC_AUTO_CLK
    };

    ledc_channel_config_t channel_conf = {
        .gpio_num=5,
        .speed_mode=LEDC_LOW_SPEED_MODE,
        .channel=LEDC_CHANNEL_0,
        .intr_type=LEDC_INTR_DISABLE,
        .timer_sel=LEDC_TIMER_0,
        .duty=10,         //[0, (2**duty_resolution)] 
        .hpoint=0
    };

    ledc_timer_config(&timer_conf);
    ledc_channel_config(&channel_conf);    

}