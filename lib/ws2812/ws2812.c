/*============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date    : 01-03-2026
File    : ws2812.c
Purpose : WS2812 Driver using RMT (ESP-IDF 5.x compliant)
============================================================*/

/*============================================================
Includes
=============================================================*/
#include "ws2812.h"
#include "driver/rmt_tx.h"
#include "esp_log.h"
#include <string.h>
#include "freertos/FreeRTOS.h"

/*============================================================
Defines
=============================================================*/
#define TAG "WS2812"
#define RMT_RESOLUTION_HZ 10000000  /* 10 MHz */

/* WS2812 Timing in ticks (0.1us per tick) */
#define T0H 4
#define T0L 9
#define T1H 8
#define T1L 5

/*============================================================
Static Variables
=============================================================*/
static rmt_channel_handle_t tx_channel = NULL;
static rmt_encoder_handle_t encoder = NULL;
static uint8_t led_buffer[3];

/*============================================================
Private Functions
=============================================================*/
static void ws2812_build_encoder(void)
{
    rmt_bytes_encoder_config_t config = {
        .bit0 = {
            .level0 = 1,
            .duration0 = T0H,
            .level1 = 0,
            .duration1 = T0L,
        },
        .bit1 = {
            .level0 = 1,
            .duration0 = T1H,
            .level1 = 0,
            .duration1 = T1L,
        },
        .flags.msb_first = 1
    };

    ESP_ERROR_CHECK(rmt_new_bytes_encoder(&config, &encoder));
}

/*============================================================
Public Functions
=============================================================*/
void ws2812_init(gpio_num_t gpio)
{
    rmt_tx_channel_config_t tx_config = {
        .gpio_num = gpio,
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = RMT_RESOLUTION_HZ,
        .mem_block_symbols = 64,
        .trans_queue_depth = 4,
    };

    ESP_ERROR_CHECK(rmt_new_tx_channel(&tx_config, &tx_channel));
    ws2812_build_encoder();
    ESP_ERROR_CHECK(rmt_enable(tx_channel));

    ESP_LOGI(TAG, "WS2812 initialized on GPIO %d", gpio);
}

void ws2812_set_color(uint8_t r, uint8_t g, uint8_t b)
{
    /* WS2812 expects GRB order */
    led_buffer[0] = g;
    led_buffer[1] = r;
    led_buffer[2] = b;

    rmt_transmit_config_t transmit_config = {
        .loop_count = 0,
    };

    ESP_ERROR_CHECK(
        rmt_transmit(
            tx_channel,
            encoder,
            led_buffer,
            sizeof(led_buffer),
            &transmit_config
        )
    );

    ESP_ERROR_CHECK(rmt_tx_wait_all_done(tx_channel, portMAX_DELAY));
}