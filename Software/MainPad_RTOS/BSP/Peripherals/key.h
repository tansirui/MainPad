#ifndef _KEY_H
#define	_KEY_H

#include "stm32f10x.h"

#define Key1_Press	1
#define Key2_Press	2

#define Key1  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)
#define Key2  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)

void Key_GPIO_Config(void);
uint8_t Key_Scan(void); 

#endif 

