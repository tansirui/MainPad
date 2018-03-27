#include "ucos_ii.h"

/************************************************
�������� �� main
��    �� �� ���������
��    �� �� ��
�� �� ֵ �� int
��    �� �� strongerHuang
*************************************************/
int main(void)
{
  /* 1��OS��ʼ�� */
  OSInit();

  /* 2���������� */
  OSTaskCreateExt((void (*)(void *)) AppTaskStart,
                  (void           *) 0,
                  (OS_STK         *)&TaskStartStk[TASK_START_STK_SIZE - 1],
                  (INT8U           ) TASK_START_PRIO,
                  (INT16U          ) TASK_START_PRIO,
                  (OS_STK         *)&TaskStartStk[0],
                  (INT32U          ) TASK_START_STK_SIZE,
                  (void           *) 0,
                  (INT16U          )(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

  /* 3���������� */
  OSStart();

  return 0;
}
