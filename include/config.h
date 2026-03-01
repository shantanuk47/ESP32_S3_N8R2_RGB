/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : config.h
Purpose : Hardware configuration abstraction layer
============================================================*/

#ifndef CONFIG_H
#define CONFIG_H

#include "driver/gpio.h"

/*============================================================
Board Identification
=============================================================*/
#define BOARD_NAME          "ESP32-S3 N8R2 (HW-678)"

/*============================================================
WS2812 Configuration
=============================================================*/
#define CONFIG_LED_GPIO 48
#define WS2812_LED_COUNT    1

#endif