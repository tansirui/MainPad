#ifndef _MOTOR_H
#define _MOTOR_H
/*
TIM	TIM1	TIM2	TIM3	TIM4	TIM5	TIM8
CH1	PA8		PA0		PA6		PB6		PA0		PC6
CH2	PA9		PA1		PA7		PB7		PA1		PC7
CH3 PA10	PA2		PB0		PB8		PA2		PC8
CH4	PA11	PA3		PB1		PB9		PA3		PC9
*/
#include "stm32f10x.h"

#define Moto_PwmMax 1000

void PWM_OUT_Config(void);
void moto_STOP(void);
void moto_PwmRflash(s16 *Moter);

#endif
