#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "driver/timer.h"

#define GPIO_LED GPIO_NUM_2 
#define GPIO_BTN GPIO_NUM_4 

void timer_callback(void *param)
{
  static bool ON;
  ON = !ON;
  
  gpio_set_level(GPIO_NUM_2, ON);
}

esp_err_t timer0_0_init()
{
    timer_config_t myTimer;
    myTimer.alarm_en = TIMER_ALARM_DIS;
    myTimer.auto_reload = TIMER_AUTORELOAD_DIS;
    myTimer.clk_src = TIMER_SRC_CLK_DEFAULT;
    myTimer.counter_dir = TIMER_COUNT_UP ;
    myTimer.counter_en = TIMER_PAUSE;
    myTimer.divider = 80;
    myTimer.intr_type = TIMER_INTR_LEVEL;

    esp_err_t err = timer_init(TIMER_GROUP_0, TIMER_0, &myTimer);
    return err;
}

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

void app_main() 
{
    double timer0_0_value = 0;
    timer0_0_init();
    btn_config(GPIO_BTN);
    led_config(GPIO_LED);

    timer_start(TIMER_GROUP_0, TIMER_0);

    while (1)
    {
        if(gpio_get_level(GPIO_BTN) == 0)
        {
            timer_get_counter_time_sec(TIMER_GROUP_0, TIMER_0, &timer0_0_value);
            printf("Timer value is %f\n", timer0_0_value);
        } 
    }
}