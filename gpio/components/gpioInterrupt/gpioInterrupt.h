#ifndef _GPIO_INTERRUPT_H_
#define _GPIO_INTERRUPT_H_

#define INPUT_INT_PIN   (6)
#define INPUT_INT_BIT_MASK  (1<<INPUT_INT_PIN)

void gpio_int_config(void);

#endif