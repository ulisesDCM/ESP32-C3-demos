#include "dac.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "driver/dac_common.h"

#define LOG_TAG ("dac.c")

/* 
    255 = 3.3v
    Resolution  8-bits 
    Maximum voltage 3.3V
*/

void init_dac(void)
{
    dac_output_enable(DAC_CHANNEL_1);
    dac_output_voltage(DAC_CHANNEL_1, 255 );        
}