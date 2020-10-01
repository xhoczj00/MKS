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
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void)
{
	uint32_t pole = 0xA9DDCA80; // SOS pole
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;
	/* Rozblikani LED */
	for (volatile uint32_t q = 0; q < 4; q++) // cyklus pro prepinani LED
	{
		GPIOA->ODR ^= (1<<5); // toggle
		for (volatile uint32_t j = 0; j < 100000; j++) {} // delay
	}
	/* Blikani v morseovce */
	for(;;)
	{
		for (volatile uint32_t i = 0; i < 32; i++) // cyklus pro cteni jednotlivych bitu pole
		{
			if ((pole & 0x80000000)== 1) GPIOA->BSRR = (1<<5); // porovnani jestli je MSB == 1 a nastaveni LED
			else GPIOA->BRR = (1<<5); // resetovani LED
			pole <<= 1; // posun o bit
			for (volatile uint32_t j = 0; j < 100000; j++) {} // delay
		}
	}
	;
}
