#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "test1.h"		//Test component inside of the src folder.
#include "myGPIO.h"		//Test component outside of the src folder.

#define LOG_TAG_MAIN		"main.c"

void app_main(void)
{
	int x=0, y=100;

	while(1)
	{
		test_sum(x,y);
		test_my_gpio();
		ESP_LOGI(LOG_TAG_MAIN, "%d + %d = %d",x,y,test_sum(x, y));

		x++;
		y++;
		vTaskDelay(1000/ portTICK_PERIOD_MS);
	}
}
