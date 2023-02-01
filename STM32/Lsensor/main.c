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

	
	unsigned int adcx,T;
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

