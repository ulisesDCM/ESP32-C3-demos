#ifndef _GPIO_INPUT_H_
#define _GPIO_INPUT_H_

#define SWITCH0_PIN     (5)
#define SWITCH1_PIN     (4)
#define SWITCH0_PIN_MASK    (1<<SWITCH0_PIN)
#define SWITCH1_PIN_MASK    (1<<SWITCH1_PIN)
#define SWITCH_BIT_MASK     (SWITCH0_PIN_MASK | SWITCH1_PIN_MASK)

typedef enum
{
    SWITCH0=SWITCH0_PIN,
    SWITCH1=SWITCH1_PIN
}eSWITCH;

void input_switch_configure(void);
int get_switch_state(eSWITCH sw);
void create_switch_task(void);

#endif