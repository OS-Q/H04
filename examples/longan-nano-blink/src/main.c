#include <stdio.h>
#include "gd32vf103.h"
#include "systick.h"

/* BUILTIN LED OF LONGAN BOARDS IS PIN PC13 */

#define LED_PIN GPIO_PIN_13
#define LED_GPIO_PORT GPIOC
#define LED_GPIO_CLK RCU_GPIOC

void longan_led_init()
{
    /* enable the led clock */
    rcu_periph_clock_enable(LED_GPIO_CLK);
    /* configure led GPIO port */ 
    gpio_init(LED_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED_PIN);

    GPIO_BC(LED_GPIO_PORT) = LED_PIN;
}

void longan_led_on()
{
    GPIO_BOP(LED_GPIO_PORT) = LED_PIN;
}

void longan_led_off()
{
    GPIO_BC(LED_GPIO_PORT) = LED_PIN;
}
/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    longan_led_init();

    while(1){
        /* turn on builtin led */
        longan_led_on();
        delay_1ms(1000);
        /* turn off uiltin led */
        longan_led_off();
        delay_1ms(1000);
    }
}
