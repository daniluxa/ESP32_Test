#include "adc.h"

void adc_init(esp_adc_cal_characteristics_t *adc1_chars, int adc_num, int adc_channel, int attenuation_param)
{
    esp_adc_cal_characterize(adc_num, attenuation_param, ADC_WIDTH_BIT_DEFAULT, 0, adc1_chars);

    adc1_config_width(ADC_WIDTH_BIT_DEFAULT); // 12 bit
    adc1_config_channel_atten(adc_channel, attenuation_param);
}
