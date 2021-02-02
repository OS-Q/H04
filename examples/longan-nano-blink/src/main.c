/*******************************************************************************
****版本：V1.0.0
****平台：P08
****日期：2021-02-02
****作者：Qitas
****版权：OS-Q
*******************************************************************************/

#include "gd32vf103.h"
#include "systick.h"
#include <stdio.h>

/* BUILTIN LED OF LONGAN BOARDS IS PIN PC13 */
#define LED_PIN         GPIO_PIN_1
#define LED_GPIO_PORT   GPIOA
#define LED_GPIO_CLK    RCU_GPIOA
/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void longan_led_init()
{
    /* enable the led clock */
    rcu_periph_clock_enable(LED_GPIO_CLK);
    /* configure led GPIO port */
    gpio_init(LED_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED_PIN);
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_1);
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_2);

    GPIO_BC(LED_GPIO_PORT) = LED_PIN;
    GPIO_BC(GPIOA) = GPIO_PIN_1;
    GPIO_BC(GPIOA) = GPIO_PIN_2;
}

void longan_led_on()
{
    GPIO_BOP(LED_GPIO_PORT) = LED_PIN;
    GPIO_BC(GPIOA) = GPIO_PIN_1;
}

void longan_led_off()
{
    GPIO_BC(LED_GPIO_PORT) = LED_PIN;
    GPIO_BOP(GPIOA) = GPIO_PIN_1;
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：
**输出参数 ：
*******************************************************************************/
int main(void)
{
    longan_led_init();

    while(1)
    {
        /* turn on builtin led */
        longan_led_on();
        delay_1ms(1000);
        // GPIO_BC(GPIOA) = GPIO_PIN_2;
        // delay_1ms(1000);
        // GPIO_BOP(GPIOA) = GPIO_PIN_2;
        /* turn off uiltin led */
        longan_led_off();
        delay_1ms(1000);
    }
}

/*---------------------------(C) COPYRIGHT 2021 OS-Q -------------------------*/
