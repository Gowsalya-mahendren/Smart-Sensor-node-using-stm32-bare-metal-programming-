/*
 * DHT11_sensor.h
 *
 *  Created on: 17 Feb 2026
 *      Author: gowsalya
 */

#ifndef HC_SR05_H_
#define HC_SR05_H_



#endif /* HC_SR05_H_ */
#include "stm32f4xx.h"
#include <core_cm4.h>

#define GPIO_CLOCK_EN (1UL<<0)
#define SYSCFG_EN (1UL<<14)
extern volatile int motion_flag;
#define USART_PIN (1U<<9)
#define BAUDRATE 115200
#define APB2_FREQ 16000000
void init();
void usart_init();
void set_baudrate(USART_TypeDef * USARTx,uint32_t periheral_clock,uint32_t Baudrate);
void usart_write_string(USART_TypeDef * USARTx,char *str);
