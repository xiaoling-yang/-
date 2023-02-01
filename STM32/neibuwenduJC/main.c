#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "usmart.h"
#include "adc.h"

//ALIENTEK ̽����STM32F407������ ʵ��13
//LCD��ʾʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

int main(void)
{ 
	double Tempt,T;
	
	unsigned int adcx;
 	u16 K;
	u8 lcd_id[12];				//���LCD ID�ַ���
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);      //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	usmart_dev.init(168);//SystemCoreClock/1000000
	LED_Init();					  //��ʼ��LED
 	LCD_Init();           //��ʼ��LCD FSMC�ӿ�
	Adc_Init();
	POINT_COLOR=BLACK;      //������ɫ����ɫ
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id����
		LCD_ShowString(30,130,200,24,24,"ADC_CH16_VOTL:");			 	
	LCD_ShowString(30,226,300,24,24,"ADC_CH16_Temperature:00.00");
	while(1) 
	{		 
		
		adcx=Get_Adc_Average(ADC_Channel_16,10);
		
		T=(float)adcx*(3.3/4096);
		Tempt=(T-0.76)/0.0025+25;
	
		
		LCD_ShowxNum(30+14*12,130,adcx,4,24,0);
		
//			Tempt	=Tempt*100;
//		adcx=Tempt;
//		Tempt=Tempt-adcx;
		Tempt=Tempt*100;
		K=Tempt;
		LCD_ShowxNum(30+21*12,226,K/100,2,24,0);
		LCD_ShowxNum(30+24*12,226,K%100,2,24,0);
//		LCD_ShowxNum(30+14*12,300,K,4,24,0);
		delay_ms(200);
		
		
		
		
		
		
			
		}
	  
////		LCD_ShowChar(30,50,1,16,1);
////		LCD_ShowChar(40,60,2,16,1);
////		LCD_ShowString(30,70,200,16,16,"TFTLCD TEST");
////		LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
//// 		LCD_ShowString(30,110,200,16,16,lcd_id);		//��ʾLCD ID	      					 
////		LCD_ShowString(30,130,200,12,12,"2023/1/18");	      					 
////	  x++;
//		if(x==12)x=0;
//		LED0=!LED0;	 
//		delay_ms(1000);	
	} 

