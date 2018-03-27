/*****************************************************************************
 * �ļ���: key.c
 * ��  ��: SiruiTan
 * ʵ��ƽ̨��MainPad 
 * ��  ��: 2017.6.19
 * ��  ��: V1.0
 * ��  ��: ����ֱ�ӽӵ� �����ڲ�����
					 ��ʱ��������
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




