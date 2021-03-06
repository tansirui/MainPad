/**
  ********************************  STM32F10x  *********************************
  * @文件名     ： bsp.c
  * @作者       ： strongerHuang
  * @库版本     ： V3.5.0
  * @文件版本   ： V1.0.0
  * @日期       ： 2016年06月28日
  * @摘要       ： BSP板级支持包头文件
  ******************************************************************************/

/* 定义防止递归包含 ----------------------------------------------------------*/
#ifndef _BSP_H
#define _BSP_H

/* 包含的头文件 --------------------------------------------------------------*/
#include "stm32f10x.h"


/* 宏定义 --------------------------------------------------------------------*/
#define PORT_LED                  GPIOD
#define PIN_LED0                  GPIO_Pin_1
#define PIN_LED1                  GPIO_Pin_0
//#define PIN_LED2                  GPIO_Pin_8
//#define PIN_LED3                  GPIO_Pin_9

/* LED开关 */
#define LED0_ON                   (PORT_LED->BRR  = PIN_LED0)
#define LED0_OFF                  (PORT_LED->BSRR = PIN_LED0)
#define LED0_TOGGLE               (PORT_LED->ODR ^= PIN_LED0)
#define LED1_TOGGLE               (PORT_LED->ODR ^= PIN_LED1)
//#define LED2_TOGGLE               (PORT_LED->ODR ^= PIN_LED2)
//#define LED3_TOGGLE               (PORT_LED->ODR ^= PIN_LED3)


/* 函数申明 ------------------------------------------------------------------*/
void BSP_Initializes(void);


#endif /* _BSP_H */

/**** Copyright (C)2016 strongerHuang. All Rights Reserved **** END OF FILE ****/
