#include <stdio.h>
#include "connect.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include <string.h>

/* Free API for weather: https://open-meteo.com/ */

#define MAIN_LOG_TAG        ("main.c")
extern const uint8_t cert[] asm("_binary_re_cer_start");
// extern const uint8_t cert[] asm("_binary_amazon_cer_start");
typedef struct chunk_payload_t{
    uint8_t *buffer;
    int buffer_index;
}chunk_payload_t;

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
            // ESP_LOGI(MAIN_LOG_TAG, "Length =%d",evt->data_len);
            // printf("%.*s\n",evt->data_len, (char *) evt->data);
        // ESP_LOGI(TAG, "Length=%d", evt->data_len);
        // printf("%.*s\n", evt->data_len, (char *)evt->data);
        chunk_payload_t *chunk_payload = evt->user_data;
        chunk_payload->buffer = realloc(chunk_payload->buffer
                                ,chunk_payload->buffer_index + evt->data_len + 1);
        memcpy(&chunk_payload->buffer[chunk_payload->buffer_index],
                    (uint8_t *) evt->data, 
                    evt->data_len );
        chunk_payload->buffer_index = chunk_payload->buffer_index + evt->data_len;
        chunk_payload->buffer[chunk_payload->buffer_index] = 0;
        // printf("buffer******** %s\n",chunk_payload->buffer);
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
    chunk_payload_t chunk_payload ={0};

    esp_http_client_config_t http_config = {
        .url="https://api.open-meteo.com/v1/forecast?latitude=32.5027&longitude=-117.0037&daily=uv_index_max&timezone=America%2FLos_Angeles",
        .method=HTTP_METHOD_GET,
        .event_handler=on_event_client,
        .user_data=&chunk_payload,
        .cert_pem=(char *)cert
        };
    esp_http_client_handle_t client = esp_http_client_init(&http_config);
    // esp_http_client_set_header(client,"latitude","32.5027");
    // esp_http_client_set_header(client,"longitude","-117.0037");
    // esp_http_client_set_header(client,"daily","uv_index_max");
    // esp_http_client_set_header(client,"timezone","America%2FLos_Angeles");

    esp_err_t error = esp_http_client_perform(client);
    if(error==ESP_OK){
        ESP_LOGI(MAIN_LOG_TAG, "HTTP GET status = %d, result = %s",
            (int) esp_http_client_get_status_code(client),
            chunk_payload.buffer);
    }else{
        ESP_LOGE(MAIN_LOG_TAG, "HTTP GET request failed: %s",esp_err_to_name(error));
    }
    
    if(chunk_payload.buffer != NULL)
        free(chunk_payload.buffer);

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
