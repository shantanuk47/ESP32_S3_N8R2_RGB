/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : rgb.h
Purpose : RGB abstraction layer
============================================================*/

#ifndef RGB_H
#define RGB_H

#include <stdint.h>

void rgb_init(void);
void rgb_set_color(uint8_t r, uint8_t g, uint8_t b);
void rgb_set_brightness(uint8_t level);
void rgb_off(void);

#endif