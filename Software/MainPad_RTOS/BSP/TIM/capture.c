#include "capture.h"
/*
TIM	TIM1	TIM2	TIM3	TIM4	TIM5	TIM8
CH1	PA8		PA0		PA6		PB6		PA0		PC6
CH2	PA9		PA1		PA7		PB7		PA1		PC7
CH3 PA10	PA2		PB0		PB8		PA2		PC8
CH4	PA11	PA3		PB1		PB9		PA3		PC9
*/

u16  Rise[7],Drop[7];
u16  RC_Pwm_In[8];


u16  RC_Pwm_In_his[8];


void Nvic_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* NVIC_PriorityGroup */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
//	NVIC_InitStructure.NVIC_IRQChannel=TIM5_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	

}

/*====================================================================================================*/
/*====================================================================================================*
**���� : PWM_IN_Config
**���� : ����PWM���벶��
**���� : None
**ݔ�� : None
**��ע : None
**====================================================================================================*/
/*====================================================================================================*/
void PWM_IN_Config(void)
{
	  GPIO_InitTypeDef         GPIO_InitStructure;
	  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	  TIM_ICInitTypeDef  TIM2_ICInitStructure;

	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3, ENABLE);	 //ʹ��TIM2ʱ��
 	  RCC_APB2PeriphClockCmd(RCC_GPIO_TIM2 | RCC_GPIO_TIM3 |RCC_APB2Periph_GPIOB, ENABLE);  

	  GPIO_InitStructure.GPIO_Pin  = TIM2_CH1 | TIM2_CH2 | TIM2_CH3 | TIM2_CH4;             
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;            
	  GPIO_Init(GPIO_TIM2, &GPIO_InitStructure);	

    GPIO_InitStructure.GPIO_Pin  = TIM3_CH1 | TIM3_CH2;	
	  GPIO_Init(GPIO_TIM3, &GPIO_InitStructure);	
	
	  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;	
	  GPIO_Init(GPIOB, &GPIO_InitStructure);	

	  //��ʼ����ʱ��2 TIM2	 
	  TIM_TimeBaseStructure.TIM_Period = 0XFFFF;                   //�趨�������Զ���װֵ 
	  TIM_TimeBaseStructure.TIM_Prescaler =71; 	                   //Ԥ��Ƶ��   
	  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;      //����ʱ�ӷָ�:TDTS = Tck_tim
	  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);              //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
	
	  //��ʼ��TIM2���벶�����
	  TIM2_ICInitStructure.TIM_Channel = TIM_Channel_1;                //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPolarity =TIM_ICPolarity_Rising;	   //�����ز���
  	TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	         //���������Ƶ,����Ƶ 
  	TIM2_ICInitStructure.TIM_ICFilter = 0x00;                        //IC1F=0000 ���������˲��� ���˲�
  	TIM_ICInit(TIM2, &TIM2_ICInitStructure);
		TIM_ICInit(TIM3, &TIM2_ICInitStructure);
	
	  TIM2_ICInitStructure.TIM_Channel = TIM_Channel_2;                //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	   //�����ز���
  	TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	         //���������Ƶ,����Ƶ 
  	TIM2_ICInitStructure.TIM_ICFilter = 0x00;                        //IC1F=0000 ���������˲��� ���˲�
  	TIM_ICInit(TIM2, &TIM2_ICInitStructure);
		TIM_ICInit(TIM3, &TIM2_ICInitStructure);
		
		TIM2_ICInitStructure.TIM_Channel = TIM_Channel_3;                //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	   //�����ز���
  	TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	         //���������Ƶ,����Ƶ 
  	TIM2_ICInitStructure.TIM_ICFilter = 0x00;                        //IC1F=0000 ���������˲��� ���˲�
  	TIM_ICInit(TIM2, &TIM2_ICInitStructure);
		TIM_ICInit(TIM3, &TIM2_ICInitStructure);
		
		TIM2_ICInitStructure.TIM_Channel = TIM_Channel_4;                //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	   //�����ز���
  	TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	         //���������Ƶ,����Ƶ 
  	TIM2_ICInitStructure.TIM_ICFilter = 0x00;                        //IC1F=0000 ���������˲��� ���˲�
  	TIM_ICInit(TIM2, &TIM2_ICInitStructure);
	
	  TIM_Cmd(TIM2,ENABLE ); 
		TIM_Cmd(TIM3,ENABLE );
		
	  TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);        //��������ж� ,����CC1IE�����ж�	
	  TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE);
	  TIM_ITConfig(TIM2, TIM_IT_CC3, ENABLE);
	  TIM_ITConfig(TIM2, TIM_IT_CC4, ENABLE);	
		
		TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);        //��������ж� ,����CC1IE�����ж�	
	  TIM_ITConfig(TIM3, TIM_IT_CC2, ENABLE);
		TIM_ITConfig(TIM3, TIM_IT_CC3, ENABLE);
}
/*====================================================================================================*/
/*====================================================================================================*
**���� : TIM2_IRQHandler
**���� : TIM2�жϷ���
**���� : None
**ݔ�� : None
**��ע : None
**====================================================================================================*/
/*====================================================================================================*/
void TIM2_IRQHandler(void)
{ 
    if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)   //����1���������¼�
		{	
			TIM_ClearITPendingBit(TIM2, TIM_IT_CC1); //����жϱ�־λ
			if(GPIO_ReadInputDataBit(GPIO_TIM2,TIM2_CH1) == 1) 
			{
				  TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
          Rise[0]=TIM_GetCapture1(TIM2);
      }
			else 
			{
				  TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
          Drop[0]=TIM_GetCapture1(TIM2);
				  if(Rise[0]>Drop[0])  RC_Pwm_In[0] = 65535-Rise[0] + Drop[0];
					else 	               RC_Pwm_In[0] = Drop[0] - Rise[0];
      }			
		}	
	  
		if (TIM_GetITStatus(TIM2, TIM_IT_CC2) != RESET)   //����1���������¼�
		{	
			TIM_ClearITPendingBit(TIM2, TIM_IT_CC2); //����жϱ�־λ
			if(GPIO_ReadInputDataBit(GPIO_TIM2,TIM2_CH2) == 1) 
			{
				  TIM_OC2PolarityConfig(TIM2,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
          Rise[1]=TIM_GetCapture2(TIM2);
      }
			else 
			{
				  TIM_OC2PolarityConfig(TIM2,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
          Drop[1]=TIM_GetCapture2(TIM2);
				  if(Rise[1]>Drop[1])  RC_Pwm_In[1] = 65535-Rise[1] + Drop[1];
					else 	               RC_Pwm_In[1] = Drop[1] - Rise[1];
      }			
		}	
		
    if (TIM_GetITStatus(TIM2, TIM_IT_CC3) != RESET)            //����1���������¼�
		{	
			TIM_ClearITPendingBit(TIM2, TIM_IT_CC3); //����жϱ�־λ
			if(GPIO_ReadInputDataBit(GPIO_TIM2,TIM2_CH3) == 1) 
			{
				  TIM_OC3PolarityConfig(TIM2,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
          Rise[2]=TIM_GetCapture3(TIM2);
      }
			else 
			{
				  TIM_OC3PolarityConfig(TIM2,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
          Drop[2]=TIM_GetCapture3(TIM2);
				  if(Rise[2]>Drop[2]) RC_Pwm_In[2] = 65535-Rise[2] + Drop[2];
					else 	              RC_Pwm_In[2] = Drop[2] - Rise[2];
      }	 
		}	

    if (TIM_GetITStatus(TIM2, TIM_IT_CC4) != RESET)            //����1���������¼�
		{	
			TIM_ClearITPendingBit(TIM2, TIM_IT_CC4); //����жϱ�־λ
		  if(GPIO_ReadInputDataBit(GPIO_TIM2,TIM2_CH4) == 1) 
			{
				  TIM_OC4PolarityConfig(TIM2,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
          Rise[3]=TIM_GetCapture4(TIM2);
      }
			else 
			{
				  TIM_OC4PolarityConfig(TIM2,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
          Drop[3]=TIM_GetCapture4(TIM2);
				  if(Rise[3]>Drop[3])  RC_Pwm_In[3] = 65535-Rise[3] + Drop[3];
					else 	               RC_Pwm_In[3] = Drop[3] - Rise[3];
      }	  
		}		
}



//��ʱ���ɻص�ֵ
vu16 US100_Alt_Temp=0; 
//�����˲����õĲ���
float Alt_CuntTmep1=0,Alt_CuntTmep2=0;

float US100_Alt;


/*====================================================================================================*/
/*====================================================================================================*
**���� : TIM3_IRQHandler
**���� : TIM3�жϷ���
**���� : None
**ݔ�� : None
**��ע : None
**====================================================================================================*/
/*====================================================================================================*/
void TIM3_IRQHandler(void)
{ 
    if (TIM_GetITStatus(TIM3, TIM_IT_CC1) != RESET)   //����1���������¼�
		{	
			TIM_ClearITPendingBit(TIM3, TIM_IT_CC1); //����жϱ�־λ
			if(GPIO_ReadInputDataBit(GPIO_TIM3,TIM3_CH1) == 1) 
			{
				  TIM_OC1PolarityConfig(TIM3,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
          Rise[4]=TIM_GetCapture1(TIM3);
      }
			else 
			{
				  TIM_OC1PolarityConfig(TIM3,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
          Drop[4]=TIM_GetCapture1(TIM3);
				  if(Rise[4]>Drop[4])  RC_Pwm_In[4] = 65535-Rise[4] + Drop[4];
					else 	               RC_Pwm_In[4] = Drop[4] - Rise[4];
      }			
		}	
	  
		if (TIM_GetITStatus(TIM3, TIM_IT_CC2) != RESET)   //����1���������¼�
		{	
			TIM_ClearITPendingBit(TIM3, TIM_IT_CC2); //����жϱ�־λ
			if(GPIO_ReadInputDataBit(GPIO_TIM3,TIM3_CH2) == 1) 
			{
				  TIM_OC2PolarityConfig(TIM3,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
          Rise[5]=TIM_GetCapture2(TIM3);
      }
			else 
			{
				  TIM_OC2PolarityConfig(TIM3,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
          Drop[5]=TIM_GetCapture2(TIM3);
				  if(Rise[5]>Drop[5])  RC_Pwm_In[5] = 65535-Rise[5] + Drop[5];
					else 	               RC_Pwm_In[5] = Drop[5] - Rise[5];
      }			
		}	
		
	  if (TIM_GetITStatus(TIM3, TIM_IT_CC3) != RESET)   //����1���������¼�
		{	
			TIM_ClearITPendingBit(TIM3, TIM_IT_CC3); //����жϱ�־λ
			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 1) 
			{
				TIM_OC3PolarityConfig(TIM3,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
				Rise[6]=TIM_GetCapture3(TIM3);
      }
			else 
			{
				TIM_OC3PolarityConfig(TIM3,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
				Drop[6]=TIM_GetCapture3(TIM3);
				if(Rise[6]>Drop[6])  US100_Alt_Temp = 65535-Rise[6] + Drop[6];
				else 	               US100_Alt_Temp = Drop[6] - Rise[6];
 
				
//				Alt_CuntTmep2=Alt_CuntTmep1;        //����ƽ���˲�
//				Alt_CuntTmep1=US100_Alt_Temp;

//				US100_Alt=((Alt_CuntTmep1+Alt_CuntTmep2)/2)*34/2000;  //ת��ΪCM

				
				US100_Alt=US100_Alt_Temp*34/2000;  //ת��ΪCM

      }			
		}	
}
