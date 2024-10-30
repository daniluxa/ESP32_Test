#include <stdio.h>
#include "driver/ledc.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LEDC_HS_MODE LEDC_HIGH_SPEED_MODE // Режим высокой скорости
#define LEDC_HS_TIMER LEDC_TIMER_0 // Таймер
#define LEDC_HS_CHANNEL LEDC_CHANNEL_0 // Канал
#define LEDC_OUTPUT_IO 33 // Пин, к которому подключен светодиод
#define LEDC_FREQUENCY 5000 // Частота ШИМ в Гц
#define LEDC_DUTY_RES LEDC_TIMER_13_BIT // Разрешение ШИМ
#define LEDC_DUTY (8192) // Долгота импульса (50% от 16384)

static const char *TAG = "ledc_example";

void app_main(void)
{
    // Настройка таймера
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_HS_MODE,
        .timer_num = LEDC_HS_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    // Настройка канала
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_HS_MODE,
        .channel = LEDC_HS_CHANNEL,
        .intr_type = LEDC_INTR_DISABLE,
        .timer_sel = LEDC_HS_TIMER,
        .gpio_num = LEDC_OUTPUT_IO,
        .duty = LEDC_DUTY,
        .hpoint = 0
    };
    ledc_channel_config(&ledc_channel);

    // Основной цикл
    while (1) {
        // Увеличение яркости
        for (int duty = 0; duty <= LEDC_DUTY; duty += 512) 
        {
            ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CHANNEL, duty);
            ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CHANNEL);
            vTaskDelay(pdMS_TO_TICKS(100));
        }

        // Уменьшение яркости
        for (int duty = LEDC_DUTY; duty >= 0; duty -= 512) 
        {
            ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CHANNEL, duty);
            ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CHANNEL);
            vTaskDelay(pdMS_TO_TICKS(100));
        }
    }
}