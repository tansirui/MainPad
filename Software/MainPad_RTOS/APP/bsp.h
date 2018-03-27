/**
  ********************************  STM32F10x  *********************************
  * @�ļ���     �� bsp.c
  * @����       �� strongerHuang
  * @��汾     �� V3.5.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2016��06��28��
  * @ժҪ       �� BSP�弶֧�ְ�ͷ�ļ�
  ******************************************************************************/

/* �����ֹ�ݹ���� ----------------------------------------------------------*/
#ifndef _BSP_H
#define _BSP_H

/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "stm32f10x.h"


/* �궨�� --------------------------------------------------------------------*/
#define PORT_LED                  GPIOD
#define PIN_LED0                  GPIO_Pin_1
#define PIN_LED1                  GPIO_Pin_0
//#define PIN_LED2                  GPIO_Pin_8
//#define PIN_LED3                  GPIO_Pin_9

/* LED���� */
#define LED0_ON                   (PORT_LED->BRR  = PIN_LED0)
#define LED0_OFF                  (PORT_LED->BSRR = PIN_LED0)
#define LED0_TOGGLE               (PORT_LED->ODR ^= PIN_LED0)
#define LED1_TOGGLE               (PORT_LED->ODR ^= PIN_LED1)
//#define LED2_TOGGLE               (PORT_LED->ODR ^= PIN_LED2)
//#define LED3_TOGGLE               (PORT_LED->ODR ^= PIN_LED3)


/* �������� ------------------------------------------------------------------*/
void BSP_Initializes(void);


#endif /* _BSP_H */

/**** Copyright (C)2016 strongerHuang. All Rights Reserved **** END OF FILE ****/
