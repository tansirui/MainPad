/*****************************************************************************
 * 文件名: key.c
 * 作  者: SiruiTan
 * 实验平台：MainPad 
 * 日  期: 2017.6.19
 * 版  本: V1.0
 * 描  述: 按键直接接地 配置内部上拉
					 延时消抖处理
*****************************************************************************/
#include "key.h" 
#include "delay.h"

void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 	
	GPIO_Init(GPIOD, &GPIO_InitStructure);	
}

uint8_t Key_Scan(void)
{
	if(Key1==0||Key2==0)
	{
		delay_ms(10);
		if(Key1==0)	return Key1_Press;
		else if(Key2==0)  return Key2_Press;	
	}
	return 0;
}




