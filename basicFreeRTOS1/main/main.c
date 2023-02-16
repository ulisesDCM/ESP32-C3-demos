#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "test1/test1.h"

#define LOG_MAIN_TAG		"main.c"

void app_main(void)
{
	int x=0, y=100;

	while(1)
	{
		test_sum(x,y);
		ESP_LOGI(LOG_MAIN_TAG, "%d + %d = %d",x,y,test_sum(x, y));
		x++;
		y++;
		vTaskDelay(1000/ portTICK_PERIOD_MS);
	}
}
