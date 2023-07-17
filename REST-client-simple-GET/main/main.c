#include <stdio.h>
#include "connect.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "nvs_flash.h"

#define MAIN_LOG_TAG        ("main.c")

esp_err_t on_event_client(esp_http_client_event_t *evt){
    switch(evt->event_id){
        case (HTTP_EVENT_ERROR):
        
        break;       /*!< This event occurs when there are any errors during execution */
        
        case (HTTP_EVENT_ON_CONNECTED):
        
        break;    /*!< Once the HTTP has been connected to the server, no data exchange has been performed */
            
        case (HTTP_EVENT_HEADERS_SENT):
        
        break;     /*!< After sending all the headers to the server */
                
        case (HTTP_EVENT_ON_HEADER):
        
        break;       /*!< Occurs when receiving each header sent from the server */
        
        case (HTTP_EVENT_ON_DATA):
            ESP_LOGI(MAIN_LOG_TAG, "Length =%d",evt->data_len);
            printf("%.*s\n",evt->data_len, (char *) evt->data);
        break;         /*!< Occurs when receiving data from the server, possibly multiple portions of the packet */
        
        case (HTTP_EVENT_ON_FINISH):
        
        break;       /*!< Occurs when finish a HTTP session */
        
        case (HTTP_EVENT_DISCONNECTED):
        
        break;    /*!< The connection has been disconnected */
        
        case (
            HTTP_EVENT_REDIRECT):
        break;        /*!< Intercepting HTTP redirects to handle them manually */

        default:
        break;
    }
    return ESP_OK;
}

void fetch_quote(void){
    esp_http_client_config_t http_config = {
        .url="http://www.google.com",
        .method=HTTP_METHOD_GET,
        .event_handler=on_event_client,
        };
    esp_http_client_handle_t client = esp_http_client_init(&http_config);
    esp_http_client_set_header(client,"Content-Type","application/json");
    esp_err_t error = esp_http_client_perform(client);
    if(error==ESP_OK){
        ESP_LOGI(MAIN_LOG_TAG, "HTTP GET status = %d, content_length = %d",
            (int) esp_http_client_get_status_code(client),
            (int) esp_http_client_get_content_length(client));
    }else{
        ESP_LOGE(MAIN_LOG_TAG, "HTTP GET request failed: %s",esp_err_to_name(error));
    }
    esp_http_client_cleanup(client);
    wifi_disconnect();
}

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    wifi_init();
    ESP_ERROR_CHECK(wifi_connect_sta("IZZI-EC7D","Taquitos9.",1000*10));
    fetch_quote();

}
