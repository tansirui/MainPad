/**
  ********************************  STM32F10x  *********************************
  *********************************  uC/OS-II  *********************************
  * @�ļ���     �� app_cfg.c
  * @����       �� strongerHuang
  * @��汾     �� V3.5.0
  * @ϵͳ�汾   �� V2.92
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2016��06��28��
  * @ժҪ       �� Ӧ������Դ�ļ�
  ******************************************************************************/
/*----------------------------------------------------------------------------
  ������־:
  2016-06-28 V1.0.0:��ʼ�汾
  ----------------------------------------------------------------------------*/
/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "app_cfg.h"
#include "app_task.h"
#include "bsp.h"


/* ȫ�ֱ��� ------------------------------------------------------------------*/
OS_STK TaskStartStk[TASK_START_STK_SIZE];
OS_STK Task1_Stk[TASK1_STK_SIZE];
OS_STK Task2_Stk[TASK2_STK_SIZE];
//OS_STK Task3_Stk[TASK3_STK_SIZE];

/************************************************
�������� �� OSTick_Init
��    �� �� ����ϵͳ�δ�ʱ�ӳ�ʼ��
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void OSTick_Init(void)
{
  RCC_ClocksTypeDef RCC_ClocksStructure;
  RCC_GetClocksFreq(&RCC_ClocksStructure);       //��ȡϵͳʱ��Ƶ��
                                                 //��ʼ��������SysTick�������ж�
  SysTick_Config(RCC_ClocksStructure.HCLK_Frequency / OS_TICKS_PER_SEC);
}

/************************************************
�������� �� AppTaskStart
��    �� �� ��������
��    �� �� p_arg --- ��ѡ����
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void AppTaskStart(void *p_arg)
{
  BSP_Initializes();                             //���ӵײ��ʼ��

  OSTick_Init();                                 //��ʼ���δ�ʱ��

  /* ��������1 */
  OSTaskCreateExt((void (*)(void *)) AppTask1,
                  (void           *) 0,
                  (OS_STK         *)&Task1_Stk[TASK1_STK_SIZE-1],
                  (INT8U           ) TASK1_PRIO,
                  (INT16U          ) TASK1_PRIO,
                  (OS_STK         *)&Task1_Stk[0],
                  (INT32U          ) TASK1_STK_SIZE,
                  (void           *) 0,
                  (INT16U          )(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

  /* ��������2 */
  OSTaskCreateExt((void (*)(void *)) AppTask2,
                  (void           *) 0,
                  (OS_STK         *)&Task2_Stk[TASK2_STK_SIZE-1],
                  (INT8U           ) TASK2_PRIO,
                  (INT16U          ) TASK2_PRIO,
                  (OS_STK         *)&Task2_Stk[0],
                  (INT32U          ) TASK2_STK_SIZE,
                  (void           *) 0,
                  (INT16U          )(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

  /* ��������3 */
//  OSTaskCreateExt((void (*)(void *)) AppTask3,
//                  (void           *) 0,
//                  (OS_STK         *)&Task3_Stk[TASK3_STK_SIZE-1],
//                  (INT8U           ) TASK3_PRIO,
//                  (INT16U          ) TASK3_PRIO,
//                  (OS_STK         *)&Task3_Stk[0],
//                  (INT32U          ) TASK3_STK_SIZE,
//                  (void           *) 0,
//                  (INT16U          )(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

//  while(1)
//  {
//    LED0_TOGGLE;
//    OSTimeDly(20);
//  }

}

/**** Copyright (C)2016 strongerHuang. All Rights Reserved **** END OF FILE ****/
