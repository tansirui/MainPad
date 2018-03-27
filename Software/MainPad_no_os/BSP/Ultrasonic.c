/*******************************超声波模块的工作原理*******************************               

1、采用IO口TRIG触发测距，给至少10us的高电平信号；
2、模块自动发送8个40KHZ的方波，自动检测是否有信号返回；
3、有信号返回，通过IO口ECHO输出一个高电平，高电平持续的时间就是超声波从发射到返回的时间;
4、测试距离=（高电平时间*声速（340M/s））/2；
5、本程序默认采用US-100超声波测距模块;
6、注意超声波模块有效高度为2M，极限不超过3M;
7、测距时，被测物体的面积不少于0.5平方米且平面尽量要求平整，否则影响测量的结果；
8、接线方法：VCC---5V
             ECHO--CH7（PB0）
             TRIG--CH8（PB1）
						 GND---GND

***********************************************************************************/

#include "Ultrasonic.h"
#include "delay.h"

//#define	ECHO_PORT      GPIOB		  //超声波模块ECHO回响信号输出端口---飞控CH7输入PWM 
//#define	ECHO_PIN       GPIO_Pin_0	//ECHO--CH7（PB0） 

#define	TRIG_PORT      GPIOB		  //超声波模块TRIG触发信号输入端口---飞控CH8输出PWM
#define	TRIG_PIN       GPIO_Pin_1 //TRIG--CH8（PB1）


/*====================================================================================================*/
/*====================================================================================================*
**函数 : Ultrasonic_Config
**功能 : 超声波配置
**输入 : None
**輸出 : None
**备注 : None
**====================================================================================================*/
/*====================================================================================================*/
void Ultrasonic_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;	       
  /* config the extiline(PB0) clock and AFIO clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO,ENABLE);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    
  GPIO_InitStructure.GPIO_Pin = TRIG_PIN;					    
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//设为推挽输出模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	         
  GPIO_Init(TRIG_PORT, &GPIO_InitStructure);	        //初始化外设GPIO 	
	GPIO_ResetBits(TRIG_PORT,TRIG_PIN);
}
/*====================================================================================================*/
/*====================================================================================================*
**函数 : Ultrasonic_Pulsing
**功能 : 启动超声波
**输入 : None
**輸出 : None
**备注 : None
**====================================================================================================*/
/*====================================================================================================*/
void Ultrasonic_Pulsing(void)
{
  GPIO_SetBits(TRIG_PORT,TRIG_PIN);		  //送>10US的高电平
	delay_us(20);
  GPIO_ResetBits(TRIG_PORT,TRIG_PIN);
}

