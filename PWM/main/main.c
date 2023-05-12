#include <stdio.h>
#include "pwm.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    init_pwm_led();
    while (1)
    {
        printf("helloWorld!\r\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);        
    }
    
}
