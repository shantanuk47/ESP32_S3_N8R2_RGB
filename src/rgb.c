/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : rgb.c
Purpose : RGB abstraction with brightness control
============================================================*/

#include "rgb.h"
#include "config.h"
#include "ws2812.h"

/*============================================================
Static Variables
============================================================*/
static uint8_t current_r = 0;
static uint8_t current_g = 0;
static uint8_t current_b = 0;
static uint8_t brightness = 255;

/*============================================================
Private Functions
============================================================*/
static uint8_t scale(uint8_t value)
{
    uint16_t scaled = (uint16_t)value * brightness;
    return (uint8_t)(scaled / 255);
}

static void apply(void)
{
    ws2812_set_color(
        scale(current_r),
        scale(current_g),
        scale(current_b)
    );
}

/*============================================================
Public Functions
============================================================*/
void rgb_init(void)
{
    ws2812_init(CONFIG_LED_GPIO);
    rgb_off();
}

void rgb_set_color(uint8_t r, uint8_t g, uint8_t b)
{
    current_r = r;
    current_g = g;
    current_b = b;
    apply();
}

void rgb_set_brightness(uint8_t level)
{
    brightness = level;
    apply();
}

void rgb_off(void)
{
    current_r = 0;
    current_g = 0;
    current_b = 0;
    apply();
}