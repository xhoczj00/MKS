/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Jan Hocz
 * @brief          : 1 cviceni
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include  "stm32f0xx.h"
#include  "sct.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void)
{
	sct_init();
	sct_led(0x7A5C36DE);
	for (volatile uint32_t j = 0;j<30000000;j++){}

	/* Blikani v morseovce */
	for(;;)
	{
		for (uint16_t i = 0;i<30000000;i+=111)
		{
			sct_value(i);
			for (volatile uint32_t j = 0;j<500000;j++){}
		}
	}
	;
}
