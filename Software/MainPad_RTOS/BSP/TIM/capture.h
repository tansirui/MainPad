#ifndef _CAPTURE_H
#define _CAPTURE_H

#include "stm32f10x.h"
/*
TIM	TIM1	TIM2	TIM3	TIM4	TIM5	TIM8
CH1	PA8		PA0		PA6		PB6		PA0		PC6
CH2	PA9		PA1		PA7		PB7		PA1		PC7
CH3 PA10	PA2		PB0		PB8		PA2		PC8
CH4	PA11	PA3		PB1		PB9		PA3		PC9
*/

#define GPIO_TIM2	     GPIOA
#define TIM2_CH1       GPIO_Pin_0
#define TIM2_CH2       GPIO_Pin_1
#define TIM2_CH3       GPIO_Pin_2
#define TIM2_CH4       GPIO_Pin_3
#define RCC_GPIO_TIM2  RCC_APB2Periph_GPIOA

#define GPIO_TIM3	     GPIOA
#define TIM3_CH1       GPIO_Pin_6
#define TIM3_CH2       GPIO_Pin_7
#define RCC_GPIO_TIM3  RCC_APB2Periph_GPIOA

extern u16  RC_Pwm_In[8];
extern u16  RC_Pwm_In_his[8];

void Nvic_Init(void);

void PWM_IN_Config(void);


#endif
