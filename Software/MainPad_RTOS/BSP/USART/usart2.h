#ifndef __USART2_H
#define	__USART2_H

#include "stm32f10x.h"
#include <stdio.h>

void USART2_Config(void);
void Nvic_Usart2_Config(void);
void Usart2_Send(unsigned char *str);
#endif 
