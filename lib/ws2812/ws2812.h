/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date :
File : ws2812.h
Purpose : WS2812 driver public interface (RMT based)
============================================================*/

#ifndef WS2812_H
#define WS2812_H

/*============================================================
Includes
=============================================================*/
#include <stdint.h>

/*============================================================
Public API
=============================================================*/
void ws2812_init(int gpio_num);
void ws2812_set_color(uint8_t r, uint8_t g, uint8_t b);
void ws2812_off(void);

#endif