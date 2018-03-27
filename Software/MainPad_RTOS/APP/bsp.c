/**
  ********************************  STM32F10x  *********************************
  * @�ļ���     �� bsp.c
  * @����       �� strongerHuang
  * @��汾     �� V3.5.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2016��06��28��
  * @ժҪ       �� BSP�弶֧�ְ�Դ�ļ�
  ******************************************************************************/
/*----------------------------------------------------------------------------
  ������־:
  2016-06-28 V1.0.0:��ʼ�汾
  ----------------------------------------------------------------------------*/
/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "bsp.h"


/************************************************
�������� �� RCC_Configuration
��    �� �� ʱ������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void RCC_Configuration(void)
{
  /* ʹ��APB2ʱ�� */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);

  /* ʹ��APB1ʱ�� */

  /* ʹ��APBʱ�� */
}

/************************************************
�������� �� GPIO_Basic_Configuration
��    �� �� �������������������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void GPIO_Basic_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  GPIO_InitStructure.GPIO_Pin =  PIN_LED0 | PIN_LED1;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                  //Ƶ��(50M)
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;                   //�������(����ʽ���)
  GPIO_Init(PORT_LED, &GPIO_InitStructure);
}

/************************************************
�������� �� BSP_Initializes
��    �� �� �ײ��ʼ��
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void BSP_Initializes(void)
{
  RCC_Configuration();                                               //ʱ������
  GPIO_Basic_Configuration();                                        //IO����
}


/**** Copyright (C)2016 strongerHuang. All Rights Reserved **** END OF FILE ****/
