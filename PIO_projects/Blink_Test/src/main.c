/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#include "main.h"
#include "gpio.h"

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

void app_main(void)
{
    gpio_init(GPIO_BTN, GPIO_MODE_INPUT, GPIO_PULLUP_ENABLE, GPIO_PULLDOWN_DISABLE, GPIO_INTR_ANYEDGE, &isrButtonPress);
    gpio_init(GPIO_LED, GPIO_MODE_OUTPUT, GPIO_PULLUP_DISABLE, GPIO_PULLDOWN_DISABLE, GPIO_INTR_DISABLE, NULL);

    bool prev_flag = btn_flag;
    while(1)
    {
        if(prev_flag != btn_flag)
        {
            printf("%d\n", btn_flag);
            prev_flag = btn_flag;
        }
        vTaskDelay(1);
    }
}
