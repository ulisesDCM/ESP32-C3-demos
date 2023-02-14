#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    char c = 0;
    char str[100];

    //Initialize the array with 0 values.
    memset(str, 0, sizeof(str));

    while(c != '\n')
    {
        c = getchar();
        if(c != 0xff)
        {
            str[strlen(str)] = c;
            printf("%c",c); 
        }
        vTaskDelay(500/portTICK_PERIOD_MS);
    }

    printf("You typed: %s\n",str);
}
