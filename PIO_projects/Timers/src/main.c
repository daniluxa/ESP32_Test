#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "driver/timer.h"
#include "esp_timer.h"
#include "driver/periph_ctrl.h"

#define GPIO_LED GPIO_NUM_2 
#define GPIO_BTN GPIO_NUM_4 

bool flag_timer = false;

// Обработчик прерывания по нажатию кнопки
static void IRAM_ATTR isrButtonPress(void* arg)
{

}

static void IRAM_ATTR timer_isr(void* arg) 
{
    gpio_set_level(GPIO_LED, 0);
    flag_timer = true;
}

esp_err_t timer0_0_init(int timer_group, int timer_num)
{
    // конфигурация таймера
    timer_config_t myTimer;
    myTimer.alarm_en = TIMER_ALARM_EN;
    myTimer.auto_reload = TIMER_AUTORELOAD_EN;
    myTimer.clk_src = TIMER_SRC_CLK_DEFAULT;
    myTimer.counter_dir = TIMER_COUNT_UP ;
    myTimer.counter_en = TIMER_PAUSE;
    myTimer.divider = 80;
    myTimer.intr_type = TIMER_INTR_LEVEL;
    esp_err_t err = timer_init(timer_group, timer_num, &myTimer);

    // настраиваем прерывание
    timer_init(timer_group, timer_num, &myTimer);
    timer_set_counter_value(timer_group, timer_num, 0);
    timer_set_alarm_value(timer_group, timer_num, 2000000);
    timer_enable_intr(timer_group, timer_num);
    timer_isr_callback_add(timer_group, timer_num, timer_isr, NULL, 0);

    return err;
}

void btn_config(int bnt_num)
{
    esp_err_t err = gpio_install_isr_service(0);
    if (err == ESP_ERR_INVALID_STATE) 
    {
        printf("ISR GPIO isr service already installed");
    };

    // Настраиваем вывод для кнопки
    gpio_pad_select_gpio(bnt_num); // режим ввода-вывода
    gpio_set_direction(bnt_num, GPIO_MODE_INPUT); // вход
    gpio_pullup_en(bnt_num); // резистор подключен к питанию
    gpio_pulldown_dis(bnt_num); // резистор отключен от земли

    // Регистрируем обработчик прерывания на нажатие кнопки
    gpio_isr_handler_add(bnt_num, isrButtonPress, NULL);
    
    // Устанавливаем тип события для генерации прерывания - по низкому уровню
    gpio_set_intr_type(bnt_num, GPIO_INTR_NEGEDGE);
    
    // Разрешаем использование прерываний
    gpio_intr_enable(bnt_num);
}

void led_config(int led_num)
{
    gpio_pad_select_gpio(led_num); // режим ввода-вывода
    gpio_set_direction(led_num, GPIO_MODE_OUTPUT); // активный выход   
}

void app_main() 
{
    double timer0_0_value = 0;
    timer0_0_init(TIMER_GROUP_0, TIMER_0);
    btn_config(GPIO_BTN);
    led_config(GPIO_LED);

    timer_start(TIMER_GROUP_0, TIMER_0);

    while (1)
    {

        if(flag_timer)
        {
            flag_timer = false;
            printf("Timer interrupt\n");
        }
        vTaskDelay(1);
    }
}