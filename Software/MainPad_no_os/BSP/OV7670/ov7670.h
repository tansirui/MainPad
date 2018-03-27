#ifndef _OV7670_H
#define _OV7670_H

#include "stm32f10x.h"
#include "include.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ο�������guanfu_wang���롣
//ALIENTEKս��STM32������V3
//OV7670 ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/1/18
//�汾��V1.0		    							    							  
//////////////////////////////////////////////////////////////////////////////////

//OV_VSYNC
#define OV7670_VSYNC  	PAin(8)			//ͬ���źż��IO
//FIFO_WEN
#define OV7670_WREN		PAout(4)		//д��FIFOʹ��
//FIFO_RCLK
#define OV7670_RCK_H	GPIOA->BSRR=1<<5//���ö�����ʱ�Ӹߵ�ƽ
#define OV7670_RCK_L	GPIOA->BRR=1<<5	//���ö�����ʱ�ӵ͵�ƽ
//FIFO_WRST
#define OV7670_WRST		PEout(2)		//дָ�븴λ
//FIFO_RRST
#define OV7670_RRST		PEout(4)  		//��ָ�븴λ
//FIFO_OE
#define OV7670_CS		PEout(6)  		//Ƭѡ�ź�(OE)

#define OV7670_DATA   GPIOC->IDR&0x00FF  					//��������˿�
	    				 
u8   OV7670_Init(void);		  	   		 
void OV7670_Light_Mode(u8 mode);
void OV7670_Color_Saturation(u8 sat);
void OV7670_Brightness(u8 bright);
void OV7670_Contrast(u8 contrast);
void OV7670_Special_Effects(u8 eft);
void OV7670_Window_Set(u16 sx,u16 sy,u16 width,u16 height);


#endif





















