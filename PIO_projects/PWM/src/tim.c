#include "driver/timer.h"
#include "esp_timer.h"
#include "tim.h"

esp_err_t timer0_0_init()
{
    // timer confiration
    timer_config_t myTimer;
    myTimer.alarm_en    = TIMER_ALARM_EN;
    myTimer.auto_reload = TIMER_AUTORELOAD_EN;
    myTimer.clk_src     = TIMER_SRC_CLK_DEFAULT;
    myTimer.counter_dir = TIMER_COUNT_UP ;
    myTimer.counter_en  = TIMER_PAUSE;
    myTimer.divider     = 80; // 1MHz
    myTimer.intr_type   = TIMER_INTR_LEVEL;

    esp_err_t err = timer_init(TIMER_GROUP_0, TIMER_0, &myTimer);

    // interrupt configuration
    timer_init(TIMER_GROUP_0, TIMER_0, &myTimer);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, 2000000);
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    timer_isr_callback_add(TIMER_GROUP_0, TIMER_0, TIMER_0_0_CALBACK, NULL, 0);

    return err;
}

esp_err_t timer0_1_init()
{
    // timer confiration
    timer_config_t myTimer;
    myTimer.alarm_en    = TIMER_ALARM_EN;
    myTimer.auto_reload = TIMER_AUTORELOAD_EN;
    myTimer.clk_src     = TIMER_SRC_CLK_DEFAULT;
    myTimer.counter_dir = TIMER_COUNT_UP ;
    myTimer.counter_en  = TIMER_PAUSE;
    myTimer.divider     = 80; // 1MHz
    myTimer.intr_type   = TIMER_INTR_LEVEL;

    esp_err_t err = timer_init(TIMER_GROUP_0, TIMER_1, &myTimer);

    // interrupt configuration
    timer_init(TIMER_GROUP_0, TIMER_1, &myTimer);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_1, 0);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_1, 2000000);
    timer_enable_intr(TIMER_GROUP_0, TIMER_1);
    timer_isr_callback_add(TIMER_GROUP_0, TIMER_1, TIMER_0_1_CALBACK, NULL, 0);

    return err;
}

esp_err_t timer1_0_init()
{
    // timer confiration
    timer_config_t myTimer;
    myTimer.alarm_en    = TIMER_ALARM_EN;
    myTimer.auto_reload = TIMER_AUTORELOAD_EN;
    myTimer.clk_src     = TIMER_SRC_CLK_DEFAULT;
    myTimer.counter_dir = TIMER_COUNT_UP ;
    myTimer.counter_en  = TIMER_PAUSE;
    myTimer.divider     = 80; // 1MHz
    myTimer.intr_type   = TIMER_INTR_LEVEL;

    esp_err_t err = timer_init(TIMER_GROUP_1, TIMER_0, &myTimer);

    // interrupt configuration
    timer_init(TIMER_GROUP_1, TIMER_0, &myTimer);
    timer_set_counter_value(TIMER_GROUP_1, TIMER_0, 0);
    timer_set_alarm_value(TIMER_GROUP_1, TIMER_0, 2000000);
    timer_enable_intr(TIMER_GROUP_1, TIMER_0);
    timer_isr_callback_add(TIMER_GROUP_1, TIMER_0, TIMER_1_0_CALBACK, NULL, 0);

    return err;
}

esp_err_t timer1_1_init()
{
    // timer confiration
    timer_config_t myTimer;
    myTimer.alarm_en    = TIMER_ALARM_EN;
    myTimer.auto_reload = TIMER_AUTORELOAD_EN;
    myTimer.clk_src     = TIMER_SRC_CLK_DEFAULT;
    myTimer.counter_dir = TIMER_COUNT_UP ;
    myTimer.counter_en  = TIMER_PAUSE;
    myTimer.divider     = 80; // 1MHz
    myTimer.intr_type   = TIMER_INTR_LEVEL;

    esp_err_t err = timer_init(TIMER_GROUP_1, TIMER_1, &myTimer);

    // interrupt configuration
    timer_init(TIMER_GROUP_1, TIMER_1, &myTimer);
    timer_set_counter_value(TIMER_GROUP_1, TIMER_1, 0);
    timer_set_alarm_value(TIMER_GROUP_1, TIMER_1, 2000000);
    timer_enable_intr(TIMER_GROUP_1, TIMER_1);
    timer_isr_callback_add(TIMER_GROUP_1, TIMER_1, TIMER_1_1_CALBACK, NULL, 0);

    return err;
}

void IRAM_ATTR TIMER_0_0_CALBACK(void* arg) 
{
   
}

void IRAM_ATTR TIMER_0_1_CALBACK(void* arg) 
{
    
}

void IRAM_ATTR TIMER_1_0_CALBACK(void* arg) 
{
    
}

void IRAM_ATTR TIMER_1_1_CALBACK(void* arg) 
{
    
}
