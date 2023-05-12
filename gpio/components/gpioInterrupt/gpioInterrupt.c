#include "gpioInterrupt.h"

#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define LOG_TAG     ("gpioInterrupt.c")

const gpio_config_t int_config = {
    .pin_bit_mask=INPUT_INT_BIT_MASK,
    .mode=GPIO_MODE_INPUT,
    .pull_up_en=GPIO_PULLUP_DISABLE,
    .pull_down_en=GPIO_PULLDOWN_ENABLE,
    .intr_type=GPIO_INTR_POSEDGE
};

QueueHandle_t interruptQueue;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    int pin_number = (int) arg;
    xQueueSendFromISR(interruptQueue, &pin_number, NULL);
}

static void int_print_count_task(void *parms)
{
    int pinNumber = 0;
    while (1)
    {
        if(xQueueReceive(interruptQueue, &pinNumber, portMAX_DELAY))
        {
            //Disable interrupt
            gpio_isr_handler_remove(INPUT_INT_PIN);

            //Wait some time while we check the button to be released.
            do
            {
                vTaskDelay(200/portTICK_PERIOD_MS);
            }while(gpio_get_level(INPUT_INT_PIN)==1);
            
            //Do some work.
            ESP_LOGI(LOG_TAG, "The interrupt on the pin %d was triggered",pinNumber);

            //Re enable the interrupt.
            gpio_isr_handler_add(INPUT_INT_PIN, gpio_isr_handler, (void *) INPUT_INT_PIN);    
        }     
    }
    
}

void gpio_int_config(void)
{
    ESP_LOGI(LOG_TAG, "Initialize the %d pin to be an interrupt",INPUT_INT_PIN);
    
    gpio_config(&int_config);

    interruptQueue = xQueueCreate(10, sizeof(int));
    xTaskCreate(&int_print_count_task, "int task", 1024*2, NULL, 2, NULL);

    gpio_install_isr_service(0);
    gpio_isr_handler_add(INPUT_INT_PIN, gpio_isr_handler, (void *) INPUT_INT_PIN);
}
