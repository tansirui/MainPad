/*****************************************************************************
 * �ļ���: TIM5.c
 * ��  ��: SiruiTan
 * ʵ��ƽ̨��MainPad 
 * ��  ��: 2017.6.20
 * ��  ��: V1.0
 * ��  ��: ���ö�ʱ��5��������
*****************************************************************************/
#include "tim5.h"
//#include "led.h"


//�ж�����Ϊ = 1/(72MHZ /psc) * arr
//�ж�����Ϊ = 1/(72MHZ /72) * 1000 = 1ms
void TIM5_Config(u16 arr,u16 psc)
{	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	
	TIM_TimeBaseStructure.TIM_Period = arr; 	//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); 
//	//���TIM5��־λ
// 	TIM_ClearFlag(TIM5,TIM_FLAG_Update);
	//ʹ��ָ����TIM5�ж�,��������ж�
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE ); 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);  
	//����TIM5
	TIM_Cmd(TIM5, ENABLE);  				 
}

u8 count = 0;
u8 flag_5ms = 0;
u8 flag_10ms = 0;
u8 flag_15ms = 0;
u8 flag_20ms = 0;

void TIM5_IRQHandler(void)  
{
	if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)  //���TIM5�����ж�
		{
			TIM_ClearITPendingBit(TIM5, TIM_IT_Update);  		//���TIM5�����жϱ�־ 
			
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


 
