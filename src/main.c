/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date :
File : main.c
Purpose : Entry point
============================================================*/

#include "version.h"
#include "esp_log.h"

void app_main(void)
{
    ESP_LOGI("FW", "Firmware Version: %s", FW_VERSION);
    ESP_LOGI("FW", "Build Date: %s %s", FW_BUILD_DATE, FW_BUILD_TIME);
}