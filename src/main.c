/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : main.c
Purpose : Application entry point
============================================================*/

#include "system_init.h"
#include "led_engine.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    system_init();

    led_engine_init();
    led_engine_set_pattern(LED_PATTERN_COLOR_CYCLE);

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}