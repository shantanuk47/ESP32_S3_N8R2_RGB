/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : led_engine.c
Purpose : LED pattern engine implementation (FreeRTOS task based)
============================================================*/

#include "led_engine.h"
#include "rgb.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

/*============================================================
Defines
============================================================*/
#define TAG "LED_ENGINE"
#define ENGINE_TASK_STACK 2048
#define ENGINE_TASK_PRIORITY 5
#define ENGINE_DELAY_MS 500

/*============================================================
Static Variables
============================================================*/
static led_pattern_t current_pattern = LED_PATTERN_OFF;

/*============================================================
Private Functions
============================================================*/

static void handle_static_patterns(void)
{
    switch (current_pattern)
    {
        case LED_PATTERN_STATIC_RED:
            rgb_set_color(255, 0, 0);
            break;

        case LED_PATTERN_STATIC_GREEN:
            rgb_set_color(0, 255, 0);
            break;

        case LED_PATTERN_STATIC_BLUE:
            rgb_set_color(0, 0, 255);
            break;

        default:
            break;
    }
}

static void handle_color_cycle(void)
{
    rgb_set_color(0, 0, 0);
    vTaskDelay(pdMS_TO_TICKS(ENGINE_DELAY_MS));

    rgb_set_color(0, 0, 0);
    vTaskDelay(pdMS_TO_TICKS(ENGINE_DELAY_MS));

    rgb_set_color(0, 0, 0);
    vTaskDelay(pdMS_TO_TICKS(ENGINE_DELAY_MS));
}

static void led_engine_task(void *pvParameters)
{
    ESP_LOGI(TAG, "LED engine task started");

    while (1)
    {
        switch (current_pattern)
        {
            case LED_PATTERN_OFF:
                rgb_off();
                break;

            case LED_PATTERN_STATIC_RED:
            case LED_PATTERN_STATIC_GREEN:
            case LED_PATTERN_STATIC_BLUE:
                handle_static_patterns();
                break;

            case LED_PATTERN_COLOR_CYCLE:
                handle_color_cycle();
                break;

            default:
                rgb_off();
                break;
        }

        vTaskDelay(pdMS_TO_TICKS(ENGINE_DELAY_MS));
    }
}

/*============================================================
Public Functions
============================================================*/

void led_engine_init(void)
{
    rgb_init();

    xTaskCreate(
        led_engine_task,
        "led_engine_task",
        ENGINE_TASK_STACK,
        NULL,
        ENGINE_TASK_PRIORITY,
        NULL
    );
}

void led_engine_set_pattern(led_pattern_t pattern)
{
    current_pattern = pattern;
}