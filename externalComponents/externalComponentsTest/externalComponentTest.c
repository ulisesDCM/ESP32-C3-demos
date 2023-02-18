#include "externalComponentTest.h"

#include "esp_log.h"
#include "driver/uart.h"

#define LOG_TAG_EXTCOMP     "externalComponentTest.c"
void extCompTest1(void)
{
    ESP_LOGI(LOG_TAG_EXTCOMP, "Running extCompTest1 function in the external component.");
}