/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2013; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                      APPLICATION CONFIGURATION
*
*                                     ST Microelectronics STM32
*                                              on the
*
*                                     Micrium uC-Eval-STM32F107
*                                        Evaluation Board
*
* Filename      : app_cfg.h
* Version       : V1.00
* Programmer(s) : EHS
*********************************************************************************************************
*/

#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__


/* 包含的头文件 --------------------------------------------------------------*/
#include "stm32f10x.h"
#include "os_cpu.h"


/* 宏定义 --------------------------------------------------------------------*/
/* 任务优先级 */
#define TASK_START_PRIO                        3
#define TASK1_PRIO                             8
#define TASK2_PRIO                             9
//#define TASK3_PRIO                             10

/* 任务堆栈大小 */
#define TASK_START_STK_SIZE                    64
#define TASK1_STK_SIZE                         64
#define TASK2_STK_SIZE                         64
//#define TASK3_STK_SIZE                         64

/* 任务堆栈变量 */
extern OS_STK TaskStartStk[TASK_START_STK_SIZE];
extern OS_STK Task1_Stk[TASK1_STK_SIZE];
extern OS_STK Task2_Stk[TASK2_STK_SIZE];
//extern OS_STK Task3_Stk[TASK3_STK_SIZE];

/* 函数申明 ------------------------------------------------------------------*/
void OSTick_Init(void);
void AppTaskStart(void *p_arg);




///*
//*********************************************************************************************************
//*                                       MODULE ENABLE / DISABLE
//*********************************************************************************************************
//*/

//#define  APP_CFG_SERIAL_EN                          DEF_ENABLED


//#define  BSP_CFG_LED_SPI2_EN                        DEF_ENABLED       /* Enable/disable LEDs on SPI port.                     */
//#define  BSP_CFG_LED_PIOC_EN                        DEF_ENABLED       /* Enable/disable PIOC LEDs.                            */


///*
//*********************************************************************************************************
//*                                              TASKS NAMES
//*********************************************************************************************************
//*/


///*
//*********************************************************************************************************
//*                                            TASK PRIORITIES
//*********************************************************************************************************
//*/

//#define  APP_TASK_START_PRIO                        4

//#define  OS_TASK_TMR_PRIO                   (OS_LOWEST_PRIO - 2)


///*
//*********************************************************************************************************
//*                                            TASK STACK SIZES
//*                             Size of the task stacks (# of OS_STK entries)
//*********************************************************************************************************
//*/

//#define  APP_TASK_START_STK_SIZE                    128
//#define  APP_CFG_TASK_LED_STK_SIZE                  128

//#define  BUFF_SIZE                                  1000


///*
//*********************************************************************************************************
//*                                    BSP CONFIGURATION: RS-232
//*********************************************************************************************************
//*/

//#define  BSP_CFG_SER_COMM_SEL             			BSP_SER_COMM_UART_02
//#define  BSP_CFG_TS_TMR_SEL                    		2


///*
//*********************************************************************************************************
//*                                     TRACE / DEBUG CONFIGURATION
//*********************************************************************************************************
//*/

//#if 0
//#define  TRACE_LEVEL_OFF                       		0
//#define  TRACE_LEVEL_INFO                      		1
//#define  TRACE_LEVEL_DEBUG                     		2
//#endif

//#define  APP_TRACE_LEVEL                			TRACE_LEVEL_INFO
//#define  APP_TRACE                      			BSP_Ser_Printf

//#define  APP_TRACE_INFO(x)            ((APP_TRACE_LEVEL >= TRACE_LEVEL_INFO)  ? (void)(APP_TRACE x) : (void)0)
//#define  APP_TRACE_DEBUG(x)           ((APP_TRACE_LEVEL >= TRACE_LEVEL_DEBUG) ? (void)(APP_TRACE x) : (void)0)



#endif
