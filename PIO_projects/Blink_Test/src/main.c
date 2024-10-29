/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "driver/gpio.h"
#include "rom/gpio.h"

#define GPIO_LED GPIO_NUM_2 

void app_main(void)
{
    gpio_pad_select_gpio(GPIO_LED);
    gpio_set_direction(GPIO_LED, GPIO_MODE_OUTPUT);
    
    while(1)
    {
        gpio_set_level(GPIO_LED, 0);
        printf("Hello world!\n");
        vTaskDelay(100);

        gpio_set_level(GPIO_LED, 1);
        printf("Hello world!\n");
        vTaskDelay(100);
    }
}
