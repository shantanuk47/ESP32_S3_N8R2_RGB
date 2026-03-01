/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : main.c
Purpose : Firmware entry point
============================================================*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "system_init.h"
#include "rgb.h"

void app_main(void)
{
    system_init();

    while (1)
    {
        rgb_set_color(255, 0, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));

        rgb_set_color(0, 255, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));

        rgb_set_color(0, 0, 255);
        vTaskDelay(pdMS_TO_TICKS(1000));

        rgb_off();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}