#ifndef __TIM_H
#define __TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

esp_err_t timer0_0_init();
esp_err_t timer0_1_init();
esp_err_t timer1_0_init();
esp_err_t timer1_1_init();

void IRAM_ATTR TIMER_0_0_CALBACK(void* arg); 
void IRAM_ATTR TIMER_0_1_CALBACK(void* arg); 
void IRAM_ATTR TIMER_1_0_CALBACK(void* arg); 
void IRAM_ATTR TIMER_1_1_CALBACK(void* arg); 

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H */
