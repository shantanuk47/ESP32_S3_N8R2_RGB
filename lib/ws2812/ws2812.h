/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : ws2812.h
Purpose : WS2812 driver public interface (RMT based)
============================================================*/

#ifndef WS2812_H
#define WS2812_H

/*============================================================
Includes
=============================================================*/
#include "driver/gpio.h"
#include <stdint.h>

/*============================================================
Public API
=============================================================*/
void ws2812_init(gpio_num_t gpio);
void ws2812_set_color(uint8_t r, uint8_t g, uint8_t b);
#endif
