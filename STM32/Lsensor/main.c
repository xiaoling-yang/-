#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "usmart.h"
#include "adc.h"

//ALIENTEK Ì½Ë÷ÕßSTM32F407¿ª·¢°å ÊµÑé13
//LCDÏÔÊ¾ÊµÑé-¿âº¯Êý°æ±¾
//¼¼ÊõÖ§³Ö£ºwww.openedv.com
//ÌÔ±¦µêÆÌ£ºhttp://eboard.taobao.com  
//¹ãÖÝÊÐÐÇÒíµç×Ó¿Æ¼¼ÓÐÏÞ¹«Ë¾  
//×÷Õß£ºÕýµãÔ­×Ó @ALIENTEK

int main(void)
{ 

	
	unsigned int adcx,T;
 	u16 K;
	u8 lcd_id[12];				//´æ·ÅLCD ID×Ö·û´®
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//ÉèÖÃÏµÍ³ÖÐ¶ÏÓÅÏÈ¼¶·Ö×é2
	delay_init(168);      //³õÊ¼»¯ÑÓÊ±º¯Êý
	uart_init(115200);		//³õÊ¼»¯´®¿Ú²¨ÌØÂÊÎª115200
	usmart_dev.init(168);//SystemCoreClock/1000000
	LED_Init();					  //³õÊ¼»¯LED
 	LCD_Init();           //³õÊ¼»¯LCD FSMC½Ó¿Ú
	Adc_Init();
	POINT_COLOR=BLACK;      //»­±ÊÑÕÉ«£ººìÉ«
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//½«LCD ID´òÓ¡µ½lcd_idÊý×é¡
		LCD_ShowString(30,130,200,24,24,"ADC_CH5_VOTL:");			 	
	LCD_ShowString(30,226,300,24,24,"ADC_CH5_Lsensor:00");
	while(1) 
	{		 
		
		adcx=Get_Adc_Average(ADC_Channel_5,10);
		if(adcx>4000)
	T=100;
		else
		{
		T=(4096-adcx)/40;
		
		}
		
	
	  
		
		LCD_ShowxNum(30+14*12,130, adcx,4,24,0);
		LCD_ShowxNum(30+16*12,226, T,4,24,0);

//		Tempt=Tempt*100;
//		
//		LCD_ShowxNum(30+21*12,226,K/100,2,24,0);
//		LCD_ShowxNum(30+24*12,226,K%100,2,24,0);
//		LCD_ShowxNum(30+14*12,300,K,4,24,0);
		delay_ms(200);
		
		
		
		
		
		
			
		}
	  

	} 

