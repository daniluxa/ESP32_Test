#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "driver/gpio.h"
#include "rom/gpio.h"

void gpio_init(int bnt_num, int gpio_mode, int pull_up, int pull_down, int isr_posedge, void *gpio_callback);

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_H */
