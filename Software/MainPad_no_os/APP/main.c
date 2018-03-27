#include "led.h"
//#include "key.h" 
#include "usart1.h"
#include "tim5.h"
#include "oled.h"
//#include "ADC_DMA.h"
//#include "motor.h"
#include "capture.h"
#include "Ultrasonic.h"

#include "usb_lib.h"
#include "hw_config.h"
#include "usb_pwr.h"	

////#include "matrix_key.h"
//#include "sdio_sdcard.h"
//#include "usart2.h"
//#include "ov7670.h"
//#include "spi_flash.h"
//#include "nRF24L01.h"
#include "delay.h"



//void LED_Config(void)
//{		
//		GPIO_InitTypeDef GPIO_InitStructure;

//		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOB, ENABLE); 													   
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;	
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
//		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
//		GPIO_Init(GPIOE, &GPIO_InitStructure);	

//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15;	
//		GPIO_Init(GPIOD, &GPIO_InitStructure);	
//	
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	
//		GPIO_Init(GPIOB, &GPIO_InitStructure);		
//														   
//		/* �ر�����led��	*/
//		GPIO_SetBits(GPIOD, GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15);	
//		GPIO_SetBits(GPIOE, GPIO_Pin_0 | GPIO_Pin_1);
//		GPIO_SetBits(GPIOB, GPIO_Pin_12);			
//}

extern u8 flag_20ms;

int main(void)
{
	delay_init();	
	Nvic_Init();	
	LED_GPIO_Config();
	PWM_IN_Config();
	OLED_Init();
	OLED_Clear();
	Ultrasonic_Config();
	USART1_Config(9600);
	TIM5_Config(5000,71);			//1/(72MHZ /72) * 5000 = 5ms	
	USB_Port_Set(0); 	//USB�ȶϿ�
	delay_ms(700);
	USB_Port_Set(1);	//USB�ٴ�����
 	Set_USBClock();   
 	USB_Interrupts_Config();	
 	USB_Init();	
	
	OLED_ShowString(0,0,"Test ultrasonic");
	OLED_ShowString(0,1,"Test ultrasonic");
	OLED_ShowString(0,2,"Test ultrasonic");
	OLED_ShowString(0,3,"Test ultrasonic");
	OLED_ShowString(0,4,"Test ultrasonic");
	OLED_ShowString(0,5,"Test ultrasonic");
	OLED_ShowString(0,6,"Test ultrasonic");

		
	while(1)
	{
		LED1(ON);
		if(flag_20ms==1)
		{
//		Ultrasonic_Pulsing();
			
			usb_printf("\r\n Test For Virtual_COM \r\n");
			usb_printf("\r\n On MainPad! \r\n");
			usb_printf("\r\n 2017.6.26 \r\n");	
//			usb_printf("\r\n CH1:%d \r\n",RC_Pwm_In);
				
			flag_20ms=0;
		}

//		OLED_ShowNum(32,1, RC_Pwm_In[5],4,12);				
//		printf("\r\n CH4:%F \r\n",US100_Alt);

//		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
//		GPIO_ResetBits(GPIOE, GPIO_Pin_1);
//		GPIO_ResetBits(GPIOE, GPIO_Pin_0);
//		delay_ms(500);
//		GPIO_SetBits(GPIOB, GPIO_Pin_12);
//		GPIO_SetBits(GPIOE, GPIO_Pin_1);
//		GPIO_SetBits(GPIOE, GPIO_Pin_0);
//		delay_ms(500);


//		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
//		delay_ms(500);
//		GPIO_SetBits(GPIOB, GPIO_Pin_12);
//		GPIO_SetBits(GPIOE, GPIO_Pin_1);
//		GPIO_SetBits(GPIOE, GPIO_Pin_0);
//		delay_ms(500);
//		
//			

//		GPIO_ResetBits(GPIOE, GPIO_Pin_1);
//		delay_ms(500);
//		GPIO_SetBits(GPIOB, GPIO_Pin_12);
//		GPIO_SetBits(GPIOE, GPIO_Pin_1);
//		GPIO_SetBits(GPIOE, GPIO_Pin_0);
//		delay_ms(500);	
//		
//		

//		GPIO_ResetBits(GPIOE, GPIO_Pin_0);
//		delay_ms(500);
//		GPIO_SetBits(GPIOB, GPIO_Pin_12);
//		GPIO_SetBits(GPIOE, GPIO_Pin_1);
//		GPIO_SetBits(GPIOE, GPIO_Pin_0);
//		delay_ms(500);
		
		
//		GPIO_ResetBits(GPIOD, GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15);
//		delay_ms(1000);			
//		GPIO_SetBits(GPIOD, GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15);
//		delay_ms(1000);				


//		GPIO_ResetBits(GPIOD, GPIO_Pin_9);
//		delay_ms(1000);			
//		GPIO_SetBits(GPIOD, GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15);
//		delay_ms(1000);	

//		GPIO_ResetBits(GPIOD, GPIO_Pin_10);
//		delay_ms(1000);			
//		GPIO_SetBits(GPIOD, GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15);
//		delay_ms(1000);	

//		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
//delay_ms(500);	
//		GPIO_SetBits(GPIOD, GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15);
//delay_ms(500);

//		GPIO_ResetBits(GPIOD, GPIO_Pin_14);
//delay_ms(500);	
//		GPIO_SetBits(GPIOD, GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15);
//delay_ms(500);

//		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
//delay_ms(500);		
//		GPIO_SetBits(GPIOD, GPIO_Pin_9 | GPIO_Pin_10| GPIO_Pin_12| GPIO_Pin_14| GPIO_Pin_15);
//delay_ms(500);

	}
}







//extern __IO uint16_t ADC_Value[Channel_Num];

//float ADC_ConvertedValueLocal[10];  

//int main(void) 	
//{
//	delay_init();
//	Nvic_Init();
//	OLED_Init();
//	OLED_Clear();
//	LED_GPIO_Config();
//	Key_GPIO_Config();
//	USART1_Config(9600);
////	TIM5_Config(5000,7199);			//1/(72MHZ /72) * 5000 = 5ms	

////	ADC1_Init();
//	PWM_OUT_Config();
//	PWM_IN_Config();
//	
////	Matrix_Init_One();
////	Matrix_Init_Two();
//	LED2(ON); 
////	printf("\r\n Test For USART!");
////	OLED_ShowString(0,0,"Test for MainPad");
//	OLED_ShowString(0,6,"Test for Capture");
////	printf("\r\n ----����һ��ADC��ͨ���ɼ�ʵ��----\r\n");
//	
//	OLED_ShowString(0,0,"CH1:");
//	OLED_ShowString(0,1,"CH2:");			
//	OLED_ShowString(0,2,"CH3:");
//	OLED_ShowString(0,3,"CH4:");		
//	OLED_ShowString(0,4,"CH5:");
//	OLED_ShowString(0,5,"CH6:");
//	
//	while(1)
//	{
//		printf("\r\n CH1:%d \r\n",RC_Pwm_In[0]);
//		printf("\r\n CH2:%d \r\n",RC_Pwm_In[1]);
//		printf("\r\n CH3:%d \r\n",RC_Pwm_In[2]);
//		printf("\r\n CH4:%d \r\n",RC_Pwm_In[3]);
//		printf("\r\n CH5:%d \r\n",RC_Pwm_In[4]);
//		printf("\r\n CH6:%d \r\n",RC_Pwm_In[5]);		
//		OLED_ShowNum(32,0,RC_Pwm_In[0],4,12);
//		OLED_ShowNum(32,1,RC_Pwm_In[1],4,12);
//		OLED_ShowNum(32,2,RC_Pwm_In[2],4,12);
//		OLED_ShowNum(32,3,RC_Pwm_In[3],4,12);
//		OLED_ShowNum(32,4,RC_Pwm_In[4],4,12);
//		OLED_ShowNum(32,5,RC_Pwm_In[5],4,12);	
//	
////		TIM4->CCR1 = 500 ;
////		TIM4->CCR2 = 600 ;
////		TIM4->CCR3 = 700 ;
////		TIM4->CCR4 = 800 ;
////		TIM1->CCR1 = 900 ;
////		TIM1->CCR2 = 1000 ;
////		TIM1->CCR3 = 1100 ;		
////		TIM1->CCR4 = 1200 ;		
//		
////			ADC_ConvertedValueLocal[0] =(float) ADC_Value[0]/4096*3.3;
////			ADC_ConvertedValueLocal[1] =(float) ADC_Value[1]/4096*3.3;
////			ADC_ConvertedValueLocal[2] =(float) ADC_Value[2]/4096*3.3;
////			ADC_ConvertedValueLocal[3] =(float) ADC_Value[3]/4096*3.3;
////			ADC_ConvertedValueLocal[4] =(float) ADC_Value[4]/4096*3.3;
////			ADC_ConvertedValueLocal[5] =(float) ADC_Value[5]/4096*3.3;
////			ADC_ConvertedValueLocal[6] =(float) ADC_Value[6]/4096*3.3;
////			ADC_ConvertedValueLocal[7] =(float) ADC_Value[7]/4096*3.3;
////			ADC_ConvertedValueLocal[8] =(float) ADC_Value[8]/4096*3.3;		
////			ADC_ConvertedValueLocal[9] =(float) ADC_Value[9]/4096*3.3;			
////			printf("\r\n CH0 value = %f V \r\n",ADC_ConvertedValueLocal[0]);
////			printf("\r\n CH1 value = %f V \r\n",ADC_ConvertedValueLocal[1]);
////			printf("\r\n CH2 value = %f V \r\n",ADC_ConvertedValueLocal[2]);
////			printf("\r\n CH3 value = %f V \r\n",ADC_ConvertedValueLocal[3]);
////			printf("\r\n CH4 value = %f V \r\n",ADC_ConvertedValueLocal[4]);
////			printf("\r\n CH5 value = %f V \r\n",ADC_ConvertedValueLocal[5]);
////			printf("\r\n CH6 value = %f V \r\n",ADC_ConvertedValueLocal[6]);
////			printf("\r\n CH7 value = %f V \r\n",ADC_ConvertedValueLocal[7]);
////			printf("\r\n CH8 value = %f V \r\n",ADC_ConvertedValueLocal[8]);
////			printf("\r\n CH9 value = %f V \r\n",ADC_ConvertedValueLocal[9]);
//		
//		
//		
////				Led1 = 0;
////		delay_ms(500);
////		
////		if(Key_Scan()==1)
////		{
////			printf("\r\n ����һ���� \r\n");			
////		}
////		if(Key_Scan()==2)
////		{
////			printf("\r\n ���������� \r\n");			
////		}
////		Led1 = 1;
////		delay_ms(500);
//		
//	}
//}



//#include "gps.h"

//#include "usb_lib.h"
//#include "hw_config.h"
//#include "usb_pwr.h"	
//extern SD_CardInfo SDCardInfo;

//void show_sdcard_info(void)
//{
//	switch(SDCardInfo.CardType)
//	{
//		case SDIO_STD_CAPACITY_SD_CARD_V1_1:printf("Card Type:SDSC V1.1\r\n");break;
//		case SDIO_STD_CAPACITY_SD_CARD_V2_0:printf("Card Type:SDSC V2.0\r\n");break;
//		case SDIO_HIGH_CAPACITY_SD_CARD:printf("Card Type:SDHC V2.0\r\n");break;
//		case SDIO_MULTIMEDIA_CARD:printf("Card Type:MMC Card\r\n");break;
//	}	
//	printf("Card ManufacturerID:%d\r\n",SDCardInfo.SD_cid.ManufacturerID);	//������ID
// 	printf("Card RCA:%d\r\n",SDCardInfo.RCA);								//����Ե�ַ
//	printf("Card Capacity:%d MB\r\n",(u32)(SDCardInfo.CardCapacity>>20));	//��ʾ����
// 	printf("Card BlockSize:%d\r\n\r\n",SDCardInfo.CardBlockSize);			//��ʾ���С
//}  






////�ⲿ�ж�8��ʼ��
//void EXTI8_Init(void)
//{												  
//	EXTI_InitTypeDef EXTI_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource8);//PA8���ж���8
// 	   	 
//	EXTI_InitStructure.EXTI_Line=EXTI_Line8;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
//	
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ�0 
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;					//�����ȼ�0 
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
//  NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���   
//}


//u8 ov_sta;	//֡�жϱ��
// //�ⲿ�ж�5~9�������
//void EXTI9_5_IRQHandler(void)
//{		 		
//	if(EXTI_GetITStatus(EXTI_Line8)==SET)	//��8�ߵ��ж�
//	{      
//		OV7670_WRST=0;	//��λдָ��		  		 
//		OV7670_WRST=1;	
//		OV7670_WREN=1;	//����д��FIFO 	 
//		ov_sta++;		//֡�жϼ�1 
//	}
//	EXTI_ClearITPendingBit(EXTI_Line8);  //���EXTI8��·����λ						  
//}


//void camera_refresh(void)
//{
//	u32 j;
// 	u16 color;	 
//	if(ov_sta)//��֡�жϸ���
//	{

//		OV7670_RRST=0;				//��ʼ��λ��ָ�� 
//		OV7670_RCK_L;
//		OV7670_RCK_H;
//		OV7670_RCK_L;
//		OV7670_RRST=1;				//��λ��ָ����� 
//		OV7670_RCK_H;
//		for(j=0;j<76800;j++)
//		{
//			OV7670_RCK_L;
//			color=GPIOC->IDR&0XFF;	//������
//			OV7670_RCK_H; 
//			color<<=8;  
//			OV7670_RCK_L;
//			color|=GPIOC->IDR&0XFF;	//������
//			OV7670_RCK_H; 
//			printf("%d",color);
//		} 
//		
// 		ov_sta=0;					//����֡�жϱ��
//	} 
//}



//__IO uint32_t DeviceID = 0;
//__IO uint32_t FlashID = 0;

//const u8 TEXT_Buffer[]={"STM32 SPI TEST"};

//#define SIZE1 sizeof(TEXT_Buffer)

//#define  FLASH_WriteAddress     0x00000
//#define  FLASH_ReadAddress      FLASH_WriteAddress
//#define  FLASH_SectorToErase    FLASH_WriteAddress




//int main(void)
//{	
//	
//	
////	u8 datatemp[SIZE1];
//	
////	u8 Status;
////	//��ƽ�� �Զ�ģʽ  ɫ�� ���� ����Ϊ�� �Աȶ�Ϊ�� ��Чģʽ ��ͨ
////	u8 lightmode=0,saturation=2,brightness=2,contrast=2,effect=0;
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	delay_init();	    
//	OLED_Init();
//	OLED_Clear();
//	LED_GPIO_Config();	
//	USART1_Config(9600);	
//	NRF24L01_Init();    //��ʼ��NRF24L01 
//	
//	printf( " \r\n �ۺϳ�ʼ����� \r\n " );		
	
	
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 
//	//DISABLE JTAG ENABLE SWD
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
//	SPI_FLASH_Init();
	
//	printf( " \r\n SPI��ʼ����� \r\n " );		
	
//	EXTI8_Init();
//		
//	Status=OV7670_Init();
	
	
//		/* SD ����ʼ�� */
//	Status = SD_Init();
//	
//	if(Status == 0) 
//	{    
//		printf( " \r\n OV7670_Init ��ʼ���ɹ� \r\n " );		
//	}
//	else
//	{
//		printf("\r\n ��ʼ��ʧ�� \r\n" );
//		printf("\r\n ���ص�Status��ֵΪ�� %d \r\n",Status );
//	}	
//	
//	OV7670_Light_Mode(lightmode);
//	OV7670_Color_Saturation(saturation);
//	OV7670_Brightness(brightness);
//	OV7670_Contrast(contrast);
// 	OV7670_Special_Effects(effect);	 	
//		OV7670_Window_Set(12,176,240,320);	//���ô���	
//	  	OV7670_CS=0;	
//	
//	printf( " \r\n OV7670������� \r\n " );		
	
	
	
	
	
//	  SPI_FLASH_CS_LOW();
	
	
	
//	DeviceID = SPI_FLASH_ReadDeviceID();
//	
//		printf( " \r\n SPI��ʼ����� \r\n " );	
//	
//	FlashID = SPI_FLASH_ReadID();
//	
//		printf( " \r\n SPI��ʼ����� \r\n " );	
//		
//		
//	printf("\r\n FlashID is 0x%X,  Manufacturer Device ID is 0x%X\r\n", FlashID, DeviceID);
//		
//	if (FlashID == sFLASH_ID)
//	{	
//		printf("\r\n ��⵽�����flash W25X64 !\r\n");
//		
////		SPI_FLASH_SectorErase(FLASH_SectorToErase);	 	 
////		
////		SPI_FLASH_BufferWrite((u8*)TEXT_Buffer, FLASH_WriteAddress, SIZE1);

//			
//		SPI_FLASH_BufferRead(datatemp, FLASH_ReadAddress, SIZE1);

//		printf("\r\n ������� ��\r\n");		
//	}
//	else
//	{    
//		printf("\r\n ��ȡ���� W25X64 ID!\n\r");
//	}
//	
//	SPI_Flash_PowerDown();  
	
	
	
	
	
//	show_sdcard_info();
	
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
//	delay_ms(1800);
//	USB_Port_Set(0); 	//USB�ȶϿ�
//	delay_ms(700);
//	USB_Port_Set(1);	//USB�ٴ�����
// 	Set_USBClock();   
// 	USB_Interrupts_Config();	
// 	USB_Init();	


//		OLED_ShowNum(64,1,Status,2,12);

//	OLED_ShowString(0,0,"Test for Flash");	
//		OLED_ShowString(0,1,datatemp);	
		
//			while(NRF24L01_Check())//��ⲻ��24L01
//	{		
//		printf("error");
//		LED1(ON);
//	}
//	OLED_ShowString(0,0,"Test for nrf");	
////	OLED_ShowString(0,0,"Test for OV7670");	
////	OLED_ShowString(0,1,"SD Size:");
////	OLED_ShowNum(64,1,SDCardInfo.CardCapacity>>20,4,12);
////	OLED_ShowString(96,1,"MB");	
////	
////	LED1(ON);
////	LED2(ON);
//	while(1)
//	{
////		camera_refresh();

//		
//		
//		
//		
////		usb_printf("\r\n Test For Virtual_COM \r\n");
////		usb_printf("\r\n On MainPad! \r\n");
////		usb_printf("\r\n 2017.6.26 \r\n");	
////		usb_printf("\r\n CH1:%d \r\n",RC_Pwm_In);
//	}
//	
//}



