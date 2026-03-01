/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date :
File : main.c
Purpose : Phase 2 – WS2812 GPIO Validation
============================================================*/

/*============================================================
Includes
=============================================================*/
#include "version.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ws2812.h"

/*============================================================
Defines
=============================================================*/
#define TAG "BOOT"
#define LED_GPIO 38

/*============================================================
Static Variables
=============================================================*/

/*============================================================
Private Function Prototypes
=============================================================*/

/*============================================================
Private Functions
=============================================================*/

/*============================================================
app_main
=============================================================*/
void app_main(void)
{
    ESP_LOGI(TAG, "================================");
    ESP_LOGI(TAG, "ESP32-S3 RGB Firmware");
    ESP_LOGI(TAG, "Version : %s", FW_VERSION);
    ESP_LOGI(TAG, "Build   : %s %s", FW_BUILD_DATE, FW_BUILD_TIME);
    ESP_LOGI(TAG, "================================");
    ESP_LOGI(TAG, "System Ready");

    ESP_LOGI(TAG, "Initializing WS2812 on GPIO %d", LED_GPIO);

    ws2812_init(LED_GPIO);

    while (1)
    {
        ESP_LOGI(TAG, "RED");
        ws2812_set_color(255, 0, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));

        ESP_LOGI(TAG, "GREEN");
        ws2812_set_color(0, 255, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));

        ESP_LOGI(TAG, "BLUE");
        ws2812_set_color(0, 0, 255);
        vTaskDelay(pdMS_TO_TICKS(1000));

        ESP_LOGI(TAG, "OFF");
        ws2812_off();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}