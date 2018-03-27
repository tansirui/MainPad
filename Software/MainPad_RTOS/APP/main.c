#include "ucos_ii.h"

/************************************************
函数名称 ： main
功    能 ： 主函数入口
参    数 ： 无
返 回 值 ： int
作    者 ： strongerHuang
*************************************************/
int main(void)
{
  /* 1、OS初始化 */
  OSInit();

  /* 2、创建任务 */
  OSTaskCreateExt((void (*)(void *)) AppTaskStart,
                  (void           *) 0,
                  (OS_STK         *)&TaskStartStk[TASK_START_STK_SIZE - 1],
                  (INT8U           ) TASK_START_PRIO,
                  (INT16U          ) TASK_START_PRIO,
                  (OS_STK         *)&TaskStartStk[0],
                  (INT32U          ) TASK_START_STK_SIZE,
                  (void           *) 0,
                  (INT16U          )(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

  /* 3、开启任务 */
  OSStart();

  return 0;
}
