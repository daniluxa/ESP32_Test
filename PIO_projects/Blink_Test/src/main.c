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
#define GPIO_BTN GPIO_NUM_4 

void btn_config(int bnt_num)
{
    gpio_pad_select_gpio(bnt_num); // режим ввода-вывода
    gpio_set_direction(bnt_num, GPIO_MODE_INPUT); // вход
    gpio_pullup_en(bnt_num); // резистор подключен к питанию
    gpio_pulldown_dis(bnt_num); // резистор отключен от земли
}

void led_config(int led_num)
{
    gpio_pad_select_gpio(led_num); // режим ввода-вывода
    gpio_set_direction(led_num, GPIO_MODE_OUTPUT); // активный выход   
}

void app_main(void)
{
    btn_config(GPIO_BTN);
    led_config(GPIO_LED);

    while(1)
    {
        gpio_set_level(GPIO_LED, gpio_get_level(GPIO_BTN));
        printf("Состояние кнопки = %d", gpio_get_level(GPIO_BTN));

        vTaskDelay(250 / portTICK_PERIOD_MS); //задержка 0,25 сек
    }
}
