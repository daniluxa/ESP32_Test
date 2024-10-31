#include "main.h"
#include "adc.h"

#define ADC1_CHANNEL_6 ADC1_CHANNEL_6
#define ADC1_NUM ADC_UNIT_1

void app_main(void)
{
    uint32_t voltage;

    esp_adc_cal_characteristics_t adc1;
    adc_init(&adc1, ADC1_NUM, ADC1_CHANNEL_6, ADC_ATTEN_DB_11);

    while (1) 
    {
        voltage = esp_adc_cal_raw_to_voltage(adc1_get_raw(ADC1_CHANNEL_6), &adc1);
        printf("ADC_CHANNEL_%d: %ld mV\n", ADC1_CHANNEL_6, voltage);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}