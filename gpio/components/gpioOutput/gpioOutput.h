#ifndef _GPIO_OUTPUT_H_
#define _GPIO_OUTPUT_H_

#define LED_RED_GPIO_PIN    (0)
#define LED_WHITE_GPIO_PIN  (1)
#define LED_RED_BIT_MASK    (1<<LED_RED_GPIO_PIN)
#define LED_WHITE_BIT_MASK  (1<<LED_WHITE_GPIO_PIN)
#define LED_BIT_MASK        (LED_RED_BIT_MASK | LED_WHITE_BIT_MASK)

typedef enum
{
    RED = LED_RED_GPIO_PIN ,
    WHITE = LED_WHITE_GPIO_PIN
}eLED;

void gpio_output_config(void);
void set_led_state(eLED led, int state);
void led_toogle_create_task(void);

#endif