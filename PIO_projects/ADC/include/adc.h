#ifndef __ADC_H
#define __ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

/*
---------ADC1---------
ADC1_CHANNEL_0	GPIO36	
ADC1_CHANNEL_1	GPIO37	
АЦП1_КАНАЛ_2	GPIO38	
ADC1_CHANNEL_3	GPIO39	
ADC1_CHANNEL_4	GPIO32	
ADC1_CHANNEL_5	GPIO33	
ADC1_CHANNEL_6	GPIO34	
ADC1_CHANNEL_7	GPIO35	

---------ADC2---------
ADC2_CHANNEL_8	GPIO25
ADC2_CHANNEL_9	GPIO26
ADC2_CHANNEL_0	GPIO4
ADC2_CHANNEL_1	GPIO0
ADC2_КАНАЛ_2	GPIO2
ADC2_CHANNEL_3	GPIO15
ADC2_CHANNEL_4	GPIO13
ADC2_CHANNEL_5	GPIO12
ADC2_CHANNEL_6	GPIO14
ADC2_CHANNEL_7	GPIO27
*/


void adc_init(esp_adc_cal_characteristics_t *adc1_chars, int adc_num, int adc_channel, int attenuation_param);

#ifdef __cplusplus
}
#endif

#endif /* __ADC_H */
