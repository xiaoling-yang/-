#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "adc.h"
#include "dacpwm.h"
#include "dma.h"

//ALIENTEK 探索者STM32F407开发板 实验18
//ADC模数转换实验-库函数版本  
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
#define sendbuff_size 32
u8 sendbuff[sendbuff_size];
const u8 sed_text[]={1};




int main(void)
{ 
	u16 i,j,t=0;

 
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);    //初始化延时函数
	uart_init(115200);	//初始化串口波特率为115200
	LED_Init();					//初始化LED 
 	LCD_Init();         //初始化LCD接口
	Adc_Init();         //初始化ADC
	POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"ADC TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/6");	  
	POINT_COLOR=BLUE;//设置字体为蓝色
//	LCD_ShowString(30,130,200,16,16,"ADC1_CH5_VAL:");	      
//	LCD_ShowString(30,150,200,16,16,"ADC1_CH5_VOL:0.000V");	//先在固定位置显示小数点      
//	LCD_ShowString(30,166,200,16,16,"DAC1_CH1_VAL:");

	
	j=sizeof(sed_text);
	USART_SendData(USART1,(u32)sed_text);
	
MYDMA_Config(DMA2_Stream7,DMA_Channel_4,(u32)&USART1->DR,(u32)sed_text,j);
	
	
	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
	
	 
	
	for(i=0;i<j;i++)
	{
		
		sendbuff[i]=sed_text[t];
	
		t++;
	
	
	}
	
	LCD_ShowString(30,182,200,16,16,"send fail!");
	while(1)
	{ 
		
		
		if(PEin(4)==0)
		{	
			
			while(!PEin(4));
			MYDMA_Enable(DMA2_Stream7,2);
			
			if(DMA_GetFlagStatus(DMA2_Stream7,DMA_FLAG_TCIF7))
		{
			LCD_ShowString(30,182,200,16,16,"send success!");
			LCD_ShowNum(30,198,j,3,16);
		}
		
			

			
			
			}
			
		
		
		

			
		
		
			
			
			LED0=!LED0;
		delay_ms(250);
		}
		

	
		
		
		
	
			
	}




