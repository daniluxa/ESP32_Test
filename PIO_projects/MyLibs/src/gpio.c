#include "gpio.h"
#include "driver/gpio.h"
#include "rom/gpio.h"

void gpio_init(int bnt_num, int gpio_mode, int pull_up, int pull_down, int isr_posedge, void *gpio_callback)
{
    gpio_install_isr_service(0);

    // gpio configuration
    gpio_config_t MyGpio;
    MyGpio.pin_bit_mask = (1ULL << bnt_num);
    MyGpio.mode         = gpio_mode;
    MyGpio.pull_up_en   = pull_up;
    MyGpio.pull_down_en = pull_down;
    MyGpio.intr_type    = isr_posedge;
    
    gpio_config(&MyGpio); 

    // add gpio callback handler
    if(gpio_callback != NULL) 
        gpio_isr_handler_add(bnt_num, gpio_callback, NULL);

    // enable interrupt
    gpio_intr_enable(bnt_num);
}