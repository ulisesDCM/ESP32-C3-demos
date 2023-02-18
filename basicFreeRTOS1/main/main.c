#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "test1.h"						//Test component inside of the src folder.
#include "myGPIO.h"						//Test component outside of the src folder.
#include "externalComponentTest.h"		//Test external component

#include "led_strip.h"

#define LOG_TAG_MAIN		"main.c"
#define BLINK_GPIO 8

static void test_components(void)
{
	static int x=0, y=100;

	test_sum(x,y);
	test_my_gpio();
	extCompTest1();
	ESP_LOGI(LOG_TAG_MAIN, "%d + %d = %d",x,y,test_sum(x, y));
	x++;
	y++;
	vTaskDelay(1000/ portTICK_PERIOD_MS);
}

static void test_strip_led(void)
{

	led_strip_handle_t led_strip;

	/* LED strip initialization with the GPIO and pixels number*/
	led_strip_config_t strip_config = {
		.strip_gpio_num = BLINK_GPIO, // The GPIO that connected to the LED strip's data line
		.max_leds = 1, // The number of LEDs in the strip,
		.led_pixel_format = LED_PIXEL_FORMAT_GRB, // Pixel format of your LED strip
		.led_model = LED_MODEL_WS2812, // LED strip model
		.flags.invert_out = false, // whether to invert the output signal (useful when your hardware has a level inverter)
	};

	led_strip_rmt_config_t rmt_config = {
		.clk_src = RMT_CLK_SRC_DEFAULT, // different clock source can lead to different power consumption
		.resolution_hz = 10 * 1000 * 1000, // 10MHz
		.flags.with_dma = false, // whether to enable the DMA feature
	};
	ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));

	while(1)
	{
		// Display RED color.
		led_strip_clear(led_strip);
		led_strip_set_pixel(led_strip,0,50,0,0);
		led_strip_refresh(led_strip);
		vTaskDelay(pdMS_TO_TICKS(500));	

		// Display Blue color.
		led_strip_clear(led_strip);
		led_strip_set_pixel(led_strip,0,0,0,50);
		led_strip_refresh(led_strip);
		vTaskDelay(pdMS_TO_TICKS(500));	

		// Display Green color.
		led_strip_clear(led_strip);
		led_strip_set_pixel(led_strip,0,0,50,0);
		led_strip_refresh(led_strip);
		vTaskDelay(pdMS_TO_TICKS(500));	
	}
}

void app_main(void)
{
	test_strip_led();
	
	while(1)
	{
		// test_components();
	}
}
