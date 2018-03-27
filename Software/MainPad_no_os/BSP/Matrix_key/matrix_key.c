/*------------------------------------------
 *�ļ�     ��matrix_key
 *����     ��ɨ��4*4����������룬���з���ֵ��
 *�������� ��PA0-PA7 
 *1-4    PA3-PA0
 *5-8    PA4-PA7
-------------------------------------------*/

#include "matrix_key.h"
#include "delay.h"

//u8 KeyValue=0;
/*------------------------------------------
 *����     ����ʼ��stm32 GPIO PA0-PA7
 *�������� ��
 *         ����  ����
 *         ����ֵ����
-------------------------------------------*/
void Matrix_Init_One(void)
{		
    GPIO_InitTypeDef GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;      
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;     //��������
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
    GPIO_ResetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);  
}
/*------------------------------------------
 *����     ��ɨ�������̣������ؼ�ֵ
 *�������� ��
 *         ����  ����
 *         ����ֵ���м����·��ؼ�ֵ
 *                 �޼�����ʱ�򷵻�0
-------------------------------------------*/
u8 Read_KeyValue_One(void)
{
    u8 KeyValue=0;
    if((GPIO_ReadInputData(GPIOA)&0xff)!=0x0f)
    {
        delay_ms(30);
        if((GPIO_ReadInputData(GPIOA)&0xff)!=0x0f)
        {
            GPIO_SetBits(GPIOA,GPIO_Pin_0);
            GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
            switch(GPIO_ReadInputData(GPIOA)&0xff)
            {
                case 0x11 : KeyValue = 1 ; break;
                case 0x21 : KeyValue = 2 ; break;
                case 0x41 : KeyValue = 3 ; break;
                case 0x81 : KeyValue = 4; break;
            }
            GPIO_SetBits(GPIOA,GPIO_Pin_1);
            GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3);
            switch(GPIO_ReadInputData(GPIOA)&0xff)
            {
                case 0x12 : KeyValue = 5 ; break;
                case 0x22 : KeyValue = 6 ; break;
                case 0x42 : KeyValue = 7; break;
                case 0x82 : KeyValue = 8; break;
            }
            GPIO_SetBits(GPIOA,GPIO_Pin_2);
            GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_3);
            switch(GPIO_ReadInputData(GPIOA)&0xff)
            {
                case 0x14 : KeyValue = 9 ; break;
                case 0x24 : KeyValue = 10 ; break;
                case 0x44 : KeyValue = 11 ; break;
                case 0x84 : KeyValue = 12; break;
            }
            GPIO_SetBits(GPIOA,GPIO_Pin_3);
            GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
            switch(GPIO_ReadInputData(GPIOA)&0xff)
            {
                case 0x18 : KeyValue = 13 ; break;
                case 0x28 : KeyValue = 14 ; break;
                case 0x48 : KeyValue = 15; break;
                case 0x88 : KeyValue = 16; break;
            }
            GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
            GPIO_ResetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
            while((GPIO_ReadInputData(GPIOA)&0xff)!=0x0f);
            return KeyValue;
        }
    }
    return 0;
}


//�ڶ������󰴼���ʼ��
void Matrix_Init_Two(void)
{		
    GPIO_InitTypeDef GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;      
    GPIO_Init(GPIOC,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;     //��������
    GPIO_Init(GPIOC,&GPIO_InitStructure);

    GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
    GPIO_ResetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);  
}


//�ڶ������󰴼���ȡֵ

u8 Read_KeyValue_Two(void)
{
    u8 KeyValue=0;
    if((GPIO_ReadInputData(GPIOC)&0xff)!=0x0f)
    {
        delay_ms(30);
        if((GPIO_ReadInputData(GPIOC)&0xff)!=0x0f)
        {
            GPIO_SetBits(GPIOC,GPIO_Pin_0);
            GPIO_ResetBits(GPIOC,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
            switch(GPIO_ReadInputData(GPIOC)&0xff)
            {
                case 0x11 : KeyValue = 1 ; break;
                case 0x21 : KeyValue = 2 ; break;
                case 0x41 : KeyValue = 3 ; break;
                case 0x81 : KeyValue = 4; break;
            }
            GPIO_SetBits(GPIOC,GPIO_Pin_1);
            GPIO_ResetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3);
            switch(GPIO_ReadInputData(GPIOC)&0xff)
            {
                case 0x12 : KeyValue = 5 ; break;
                case 0x22 : KeyValue = 6 ; break;
                case 0x42 : KeyValue = 7; break;
                case 0x82 : KeyValue = 8; break;
            }
            GPIO_SetBits(GPIOC,GPIO_Pin_2);
            GPIO_ResetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_3);
            switch(GPIO_ReadInputData(GPIOC)&0xff)
            {
                case 0x14 : KeyValue = 9 ; break;
                case 0x24 : KeyValue = 10 ; break;
                case 0x44 : KeyValue = 11 ; break;
                case 0x84 : KeyValue = 12; break;
            }
            GPIO_SetBits(GPIOC,GPIO_Pin_3);
            GPIO_ResetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
            switch(GPIO_ReadInputData(GPIOC)&0xff)
            {
                case 0x18 : KeyValue = 13 ; break;
                case 0x28 : KeyValue = 14 ; break;
                case 0x48 : KeyValue = 15; break;
                case 0x88 : KeyValue = 16; break;
            }
            GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
            GPIO_ResetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
            while((GPIO_ReadInputData(GPIOC)&0xff)!=0x0f);
            return KeyValue;
        }
    }
    return 0;
}

