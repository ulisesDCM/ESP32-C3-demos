#include <stdio.h>
#include "connect.h"
#include "nvs_flash.h"
#include "esp_log.h"
#include "esp_http_server.h"
#include "mdns.h"
#include "toogleLED.h"
#include "cJSON.h"

#define LOG_TAG     ("main.c")

static  esp_err_t on_default_url(httpd_req_t *r){
    ESP_LOGI(LOG_TAG,"URL: %s",r->uri);
    httpd_resp_sendstr(r,"hello World");

    return ESP_OK;
}


static  esp_err_t on_toogle_led(httpd_req_t *r){
    char buffer[100];
    memset(buffer,0,sizeof(buffer));
    httpd_req_recv(r, buffer, r->content_len);
    cJSON *payload=cJSON_Parse(buffer);
    cJSON *is_on_json=cJSON_GetObjectItem(payload, "is_on");
    bool is_on = cJSON_IsTrue(is_on_json);
    cJSON_Delete(payload);
    toogle_led(is_on);

    httpd_resp_set_status(r,"204 NO CONTENT");
    httpd_resp_send(r, NULL, 0);
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

    httpd_uri_t toogle_led_url={
        .uri="/api/toogle-led",
        .method=HTTP_POST,
        .handler=on_toogle_led
    };

    httpd_register_uri_handler(server, &toogle_led_url);
}

void start_mdns_server(void){
    ESP_ERROR_CHECK(mdns_init());
    mdns_hostname_set("my-esp32");
    mdns_instance_name_set("ESP32 micro-server");
}

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    init_led();
    wifi_init();
    ESP_ERROR_CHECK(wifi_connect_sta("IZZI-EC7D","Taquitos9.",1000*10));

    start_mdns_server();
    init_server();
}
