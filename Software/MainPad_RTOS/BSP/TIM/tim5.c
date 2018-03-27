/*****************************************************************************
 * 文件名: TIM5.c
 * 作  者: SiruiTan
 * 实验平台：MainPad 
 * 日  期: 2017.6.20
 * 版  本: V1.0
 * 描  述: 配置定时器5调度任务
*****************************************************************************/
#include "tim5.h"
//#include "led.h"


//中断周期为 = 1/(72MHZ /psc) * arr
//中断周期为 = 1/(72MHZ /72) * 1000 = 1ms
void TIM5_Config(u16 arr,u16 psc)
{	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	
	TIM_TimeBaseStructure.TIM_Period = arr; 	//设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); 
//	//清除TIM5标志位
// 	TIM_ClearFlag(TIM5,TIM_FLAG_Update);
	//使能指定的TIM5中断,允许更新中断
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE ); 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);  
	//开启TIM5
	TIM_Cmd(TIM5, ENABLE);  				 
}

u8 count = 0;
u8 flag_5ms = 0;
u8 flag_10ms = 0;
u8 flag_15ms = 0;
u8 flag_20ms = 0;

void TIM5_IRQHandler(void)  
{
	if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)  //检查TIM5更新中断
		{
			TIM_ClearITPendingBit(TIM5, TIM_IT_Update);  		//清除TIM5更新中断标志 
			
			count ++;
			if(count%1 == 0) flag_5ms = 1;
			if(count%2 == 0) flag_10ms = 1;
			if(count%3 == 0) flag_15ms = 1;
			if(count%4 == 0) 
			{ 
				flag_20ms = 1;
				count = 0;
			}						
		}
}


 
