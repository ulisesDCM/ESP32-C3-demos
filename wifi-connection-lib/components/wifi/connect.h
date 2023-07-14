#ifndef __CONNECT_H_
#define __CONNECT_H_

#include "esp_err.h"

void wifi_init(void);
esp_err_t wifi_connect_sta(const char *ssid, const char *pass, int timeout);

#endif