/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date :
File : main.c
Purpose : Boot validation entry point
============================================================*/

#include "version.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define TAG "BOOT"

void app_main(void)
{
    ESP_LOGI(TAG, "================================");
    ESP_LOGI(TAG, "ESP32-S3 RGB Firmware");
    ESP_LOGI(TAG, "Version : %s", FW_VERSION);
    ESP_LOGI(TAG, "Build   : %s %s", FW_BUILD_DATE, FW_BUILD_TIME);
    ESP_LOGI(TAG, "================================");
    ESP_LOGI(TAG, "System Ready");

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}