#include <stdio.h>
#include "connect.h"
#include "nvs_flash.h"
#include "esp_log.h"
#include "esp_http_server.h"

#define LOG_TAG     ("main.c")

static  esp_err_t on_default_url(httpd_req_t *r){
    ESP_LOGI(LOG_TAG,"URL: %s",r->uri);
    httpd_resp_sendstr(r,"hello World");

    return ESP_OK;
}

static void init_server(void){
    httpd_handle_t server=NULL;
    httpd_config_t config=HTTPD_DEFAULT_CONFIG();
    ESP_ERROR_CHECK(httpd_start(&server, &config));

    httpd_uri_t default_url={
        .uri="/",
        .method=HTTP_GET,
        .handler=on_default_url
    };

    httpd_register_uri_handler(server, &default_url);
}

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    wifi_init();
    ESP_ERROR_CHECK(wifi_connect_sta("IZZI-EC7D","Taquitos9.",1000*10));
    init_server();
}