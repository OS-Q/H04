/*******************************************************************************
****版本：V1.0.0
****平台：P26
****日期：2021-02-02
****作者：Qitas
****版权：OS-Q
*******************************************************************************/
#include "gd32vf103.h"
#include "systick.h"

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void delay_1ms(uint32_t count)
{
    uint64_t start_mtime, delta_mtime;

    // Don't start measuruing until we see an mtime tick
    uint64_t tmp = get_timer_value();
    do {
    start_mtime = get_timer_value();
    } while (start_mtime == tmp);

    do {
    delta_mtime = get_timer_value() - start_mtime;
    }while(delta_mtime <(SystemCoreClock/4000.0 *count ));
}

/*---------------------------(C) COPYRIGHT 2021 OS-Q -------------------------*/
