#include "connect.h"
#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define CONNECT_LOG_TAG     ("connect.c")

void wifi_init(void){

}

esp_err_t wifi_connect_sta(const char *ssid, const char *pass, int timeout){

}

void wifi_connect_ap(const char *ssid, const char *pass){

}

void wifi_disconnect(void){

}
