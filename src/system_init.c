/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : system_init.c
Purpose : System initialization implementation
============================================================*/

#include "system_init.h"
#include "version.h"
#include "esp_log.h"
#include "rgb.h"

/*============================================================
Defines
============================================================*/
#define TAG "SYSTEM"

/*============================================================
Public Functions
============================================================*/
void system_init(void)
{
    ESP_LOGI(TAG, "================================");
    ESP_LOGI(TAG, "ESP32-S3 RGB Firmware");
    ESP_LOGI(TAG, "Version : %s", FW_VERSION);
    ESP_LOGI(TAG, "Build   : %s %s", FW_BUILD_DATE, FW_BUILD_TIME);
    ESP_LOGI(TAG, "================================");
    ESP_LOGI(TAG, "System Initializing...");

    rgb_init();

    ESP_LOGI(TAG, "System Initialization Complete");
}