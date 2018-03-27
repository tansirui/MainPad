
#include "usart2.h"

char GPS_Uart2_Data[256]={ 0 };
char GPS_Data[256]={ 0 };
unsigned int GPS_Uart2_Data_Num=0;
unsigned char GPS_Uart2_Start_flag=0;
unsigned char GPS_Stop_flag=0;


void USART2_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);  //使能AFIO功能的时钟
  GPIO_PinRemapConfig(GPIO_Remap_USART2 ,ENABLE);  //进行重映射
		
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 9600;                 /*设置波特率为115200*/
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;  /*设置数据位为8位*/
	USART_InitStructure.USART_StopBits = USART_StopBits_1;       /*设置停止位为1位*/
	USART_InitStructure.USART_Parity = USART_Parity_No;          /*无奇偶校验*/    
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; /*没有硬件流控*/
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;      /*发送与接收*/
	
	USART_Init(USART2, &USART_InitStructure);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE);
}


void Nvic_Usart2_Config(void)
{
	NVIC_InitTypeDef NVIC_Usart2;																//设置中断控制器变量 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);							//设置中断优先级
	
	NVIC_Usart2.NVIC_IRQChannel = USART2_IRQn;	 								//设置为串口1全局中断
	NVIC_Usart2.NVIC_IRQChannelPreemptionPriority = 1;					//设置抢占优先级
	NVIC_Usart2.NVIC_IRQChannelSubPriority = 0;									//设置从优先级
	NVIC_Usart2.NVIC_IRQChannelCmd = ENABLE;										//IRQ通道使能
	NVIC_Init(&NVIC_Usart2);
}


void USART2_IRQHandler(void)
{
	unsigned char Data_char_usart2;	
	if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		Data_char_usart2=USART2->DR;
		if(Data_char_usart2=='$')
		{
			GPS_Uart2_Start_flag=1;
			GPS_Uart2_Data_Num=0;
		}
		if(GPS_Uart2_Start_flag==1)
		{
			GPS_Uart2_Data[GPS_Uart2_Data_Num]=Data_char_usart2;
			GPS_Uart2_Data_Num++;			
			if(Data_char_usart2=='\n')
			{
				GPS_Stop_flag=1;
				GPS_Uart2_Data_Num=0;
				GPS_Uart2_Start_flag=0;
			}	
		}
	}	
}



void Usart2_Send(unsigned char *str)
{
	while(*str != '\0')
	{		
		while(USART_GetFlagStatus(USART2, USART_FLAG_TC)==RESET);
		USART_SendData(USART2 , *str);
		str++;
	}
}

