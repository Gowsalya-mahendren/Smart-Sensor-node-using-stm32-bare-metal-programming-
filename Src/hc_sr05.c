/*
 * DHT11_sensor.c
 *
 *  Created on: 17 Feb 2026
 *      Author: gowsalya
 */
#include <hc_sr05.h>
#include<stdio.h>
#include <core_cm4.h>
volatile int motion_flag=0;

void init()
{
	//Configuring GPIO pin
	RCC->AHB1ENR |= GPIO_CLOCK_EN;

	//Configuring SYSCFG
	RCC->APB2ENR |= SYSCFG_EN;

	//Configuring Port A Pin 1 as input mode with pull down mode
	GPIOA->MODER &= ~(3<<2);
	GPIOA->PUPDR &= ~(3<<2);
	GPIOA->PUPDR |= (2<<2);

	//Configuring EXTI to PA1 in SYSCFG registers
	SYSCFG->EXTICR[0] &= ~(15<<4);

	//Configuring pin to IMR in SYSCFG
	EXTI->IMR |= (1<<1);

	//Configuring interrupt for rising edge
	EXTI->RTSR |= (1<<1);

	//Disabling falling edge interrupt
	EXTI->FTSR &= ~(1<<1);

	//clearing the pending register
	EXTI->PR |= (1<<1);

	//enabling interrupt in NVIC
	__NVIC_EnableIRQ(EXTI1_IRQn);
}

void EXTI1_IRQHandler(void)
{
	//checking whether interrupt occurred
	if (EXTI->PR & (1<<1))
	{
		//clearing the pending register
		EXTI->PR |= (1<<1);
		motion_flag=1;
	}
}

void usart_init(){

	//configuring USART Tx corresponding GPIO pin 2 port A to Alternate Function
	RCC->AHB1ENR |= (1<<0);
	GPIOA->MODER |= (1<<5);
	GPIOA->MODER &= ~(1<<4);

	//Configuring the alternative function as af07
	GPIOA->AFR[0] |= (1<<8);
	GPIOA->AFR[0] |= (1<<9);
	GPIOA->AFR[0] |= (1<<10);
	GPIOA->AFR[0] &= ~(1<<11);

	//Configure clock for USART
	RCC->APB1ENR |= (1U<<17);

	//Configure Baudrate
	set_baudrate(USART2,APB2_FREQ,BAUDRATE);

	//Enabling USART Transmission and USART enable
	USART2->CR1 = (1U<<3);
	USART2->CR1 |= (1U<<13);
}

void set_baudrate(USART_TypeDef * USARTx,uint32_t peripheral_clock,uint32_t Baudrate){
	USART2->BRR=(peripheral_clock/Baudrate);
}
void usart_write_string(USART_TypeDef * USARTx,char *str){
	while(*str){
		while (!(USARTx->SR & (1U<<7)));
		USARTx->DR = *str;
		str++;

	}
}
