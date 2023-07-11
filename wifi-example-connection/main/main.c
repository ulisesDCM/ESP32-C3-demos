#include <stdio.h>
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_http_client.h"
#include "protocol_examples_common.h"

esp_err_t clientEvent(esp_http_client_event_t *evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ON_DATA:
        printf("%.*s\n",evt->data_len, (char *) evt->data);
        break;
    
    default:
        break;
    }
    return ESP_OK;
}

void app_main(void)
{
    nvs_flash_init();
    esp_netif_init();
    esp_event_loop_create_default();
    example_connect();  

    esp_http_client_config_t clientConfig ={
        .url="http://google.com",
        .event_handler=clientEvent
    };

    esp_http_client_handle_t client = esp_http_client_init(&clientConfig);
    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}
