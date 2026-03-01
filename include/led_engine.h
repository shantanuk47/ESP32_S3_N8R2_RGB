/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : led_engine.h
Purpose : LED pattern engine interface
============================================================*/

#ifndef LED_ENGINE_H
#define LED_ENGINE_H

#include <stdint.h>

typedef enum
{
    LED_PATTERN_OFF = 0,
    LED_PATTERN_STATIC_RED,
    LED_PATTERN_STATIC_GREEN,
    LED_PATTERN_STATIC_BLUE,
    LED_PATTERN_COLOR_CYCLE
} led_pattern_t;

void led_engine_init(void);
void led_engine_set_pattern(led_pattern_t pattern);

#endif