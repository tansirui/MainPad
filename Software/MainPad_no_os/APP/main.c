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
//		/* 关闭所有led灯	*/
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
	USB_Port_Set(0); 	//USB先断开
	delay_ms(700);
	USB_Port_Set(1);	//USB再次连接
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
////	printf("\r\n ----这是一个ADC多通道采集实验----\r\n");
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
////			printf("\r\n 按键一按下 \r\n");			
////		}
////		if(Key_Scan()==2)
////		{
////			printf("\r\n 按键二按下 \r\n");			
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
//	printf("Card ManufacturerID:%d\r\n",SDCardInfo.SD_cid.ManufacturerID);	//制造商ID
// 	printf("Card RCA:%d\r\n",SDCardInfo.RCA);								//卡相对地址
//	printf("Card Capacity:%d MB\r\n",(u32)(SDCardInfo.CardCapacity>>20));	//显示容量
// 	printf("Card BlockSize:%d\r\n\r\n",SDCardInfo.CardBlockSize);			//显示块大小
//}  






////外部中断8初始化
//void EXTI8_Init(void)
//{												  
//	EXTI_InitTypeDef EXTI_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource8);//PA8对中断线8
// 	   	 
//	EXTI_InitStructure.EXTI_Line=EXTI_Line8;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
//	
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级0 
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;					//子优先级0 
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
//  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器   
//}


//u8 ov_sta;	//帧中断标记
// //外部中断5~9服务程序
//void EXTI9_5_IRQHandler(void)
//{		 		
//	if(EXTI_GetITStatus(EXTI_Line8)==SET)	//是8线的中断
//	{      
//		OV7670_WRST=0;	//复位写指针		  		 
//		OV7670_WRST=1;	
//		OV7670_WREN=1;	//允许写入FIFO 	 
//		ov_sta++;		//帧中断加1 
//	}
//	EXTI_ClearITPendingBit(EXTI_Line8);  //清除EXTI8线路挂起位						  
//}


//void camera_refresh(void)
//{
//	u32 j;
// 	u16 color;	 
//	if(ov_sta)//有帧中断更新
//	{

//		OV7670_RRST=0;				//开始复位读指针 
//		OV7670_RCK_L;
//		OV7670_RCK_H;
//		OV7670_RCK_L;
//		OV7670_RRST=1;				//复位读指针结束 
//		OV7670_RCK_H;
//		for(j=0;j<76800;j++)
//		{
//			OV7670_RCK_L;
//			color=GPIOC->IDR&0XFF;	//读数据
//			OV7670_RCK_H; 
//			color<<=8;  
//			OV7670_RCK_L;
//			color|=GPIOC->IDR&0XFF;	//读数据
//			OV7670_RCK_H; 
//			printf("%d",color);
//		} 
//		
// 		ov_sta=0;					//清零帧中断标记
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
////	//白平衡 自动模式  色度 亮度 设置为零 对比度为零 特效模式 普通
////	u8 lightmode=0,saturation=2,brightness=2,contrast=2,effect=0;
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	delay_init();	    
//	OLED_Init();
//	OLED_Clear();
//	LED_GPIO_Config();	
//	USART1_Config(9600);	
//	NRF24L01_Init();    //初始化NRF24L01 
//	
//	printf( " \r\n 综合初始化完成 \r\n " );		
	
	
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 
//	//DISABLE JTAG ENABLE SWD
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
//	SPI_FLASH_Init();
	
//	printf( " \r\n SPI初始化完成 \r\n " );		
	
//	EXTI8_Init();
//		
//	Status=OV7670_Init();
	
	
//		/* SD 卡初始化 */
//	Status = SD_Init();
//	
//	if(Status == 0) 
//	{    
//		printf( " \r\n OV7670_Init 初始化成功 \r\n " );		
//	}
//	else
//	{
//		printf("\r\n 初始化失败 \r\n" );
//		printf("\r\n 返回的Status的值为： %d \r\n",Status );
//	}	
//	
//	OV7670_Light_Mode(lightmode);
//	OV7670_Color_Saturation(saturation);
//	OV7670_Brightness(brightness);
//	OV7670_Contrast(contrast);
// 	OV7670_Special_Effects(effect);	 	
//		OV7670_Window_Set(12,176,240,320);	//设置窗口	
//	  	OV7670_CS=0;	
//	
//	printf( " \r\n OV7670设置完成 \r\n " );		
	
	
	
	
	
//	  SPI_FLASH_CS_LOW();
	
	
	
//	DeviceID = SPI_FLASH_ReadDeviceID();
//	
//		printf( " \r\n SPI初始化完成 \r\n " );	
//	
//	FlashID = SPI_FLASH_ReadID();
//	
//		printf( " \r\n SPI初始化完成 \r\n " );	
//		
//		
//	printf("\r\n FlashID is 0x%X,  Manufacturer Device ID is 0x%X\r\n", FlashID, DeviceID);
//		
//	if (FlashID == sFLASH_ID)
//	{	
//		printf("\r\n 检测到华邦串行flash W25X64 !\r\n");
//		
////		SPI_FLASH_SectorErase(FLASH_SectorToErase);	 	 
////		
////		SPI_FLASH_BufferWrite((u8*)TEXT_Buffer, FLASH_WriteAddress, SIZE1);

//			
//		SPI_FLASH_BufferRead(datatemp, FLASH_ReadAddress, SIZE1);

//		printf("\r\n 测试完成 ！\r\n");		
//	}
//	else
//	{    
//		printf("\r\n 获取不到 W25X64 ID!\n\r");
//	}
//	
//	SPI_Flash_PowerDown();  
	
	
	
	
	
//	show_sdcard_info();
	
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	delay_ms(1800);
//	USB_Port_Set(0); 	//USB先断开
//	delay_ms(700);
//	USB_Port_Set(1);	//USB再次连接
// 	Set_USBClock();   
// 	USB_Interrupts_Config();	
// 	USB_Init();	


//		OLED_ShowNum(64,1,Status,2,12);

//	OLED_ShowString(0,0,"Test for Flash");	
//		OLED_ShowString(0,1,datatemp);	
		
//			while(NRF24L01_Check())//检测不到24L01
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



