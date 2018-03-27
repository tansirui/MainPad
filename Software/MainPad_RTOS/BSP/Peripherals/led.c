/*****************************************************************************
 * 文件名: led.c
 * 作  者: SiruiTan
 * 实验平台：MainPad 
 * 日  期: 2017.6.19
 * 版  本: V1.0
 * 描  述: 支持位带操作
*****************************************************************************/
#include "led.h"   

void LED_GPIO_Config(void)
{		
		GPIO_InitTypeDef GPIO_InitStructure;

		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD, ENABLE); 													   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_Init(GPIOD, &GPIO_InitStructure);																	   
														   
		/* 关闭所有led灯	*/
		GPIO_SetBits(GPIOD, GPIO_Pin_0|GPIO_Pin_1);	 
}


/*********************************************END OF FILE**********************/
