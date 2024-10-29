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

bool btn_flag = false;

static void IRAM_ATTR isrButtonPress(void* arg)
{
    if(gpio_get_level(GPIO_BTN) == 0)
        btn_flag = true;
    else
        btn_flag = false;
}

void btn_config(int bnt_num)
{
    // Устанавливаем сервис GPIO ISR service
    esp_err_t err = gpio_install_isr_service(0);
    
    // Настраиваем вывод для кнопки
    gpio_pad_select_gpio(bnt_num); // режим ввода-вывода
    gpio_set_direction(bnt_num, GPIO_MODE_INPUT); // вход
    gpio_pullup_en(bnt_num); // резистор подключен к питанию
    gpio_pulldown_dis(bnt_num); // резистор отключен от земли

    // Регистрируем обработчик прерывания на нажатие кнопки
    gpio_isr_handler_add(bnt_num, isrButtonPress, NULL);
    
    // Устанавливаем тип события для генерации прерывания - по низкому уровню
    gpio_set_intr_type(bnt_num, GPIO_INTR_ANYEDGE);
    
    // Разрешаем использование прерываний
    gpio_intr_enable(bnt_num);
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
    bool prev_flag = btn_flag;
    while(1)
    {
        if(prev_flag != btn_flag)
        {
            printf("%d\n", btn_flag);
            prev_flag = btn_flag;
        }
    }
}
