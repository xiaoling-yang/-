#include "sys.h"
#include "delay.h"
#include "lsensor.h"







void Adc_Init(void)
{
	 GPIO_InitTypeDef GPIO_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);//使能外部时钟。
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3,ENABLE);
	
	
	
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7;//初始化PA7。
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);

	
	
	ADC_CommonInitStructure.ADC_Mode=ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler=ADC_Prescaler_Div4;
	ADC_CommonInitStructure.ADC_DMAAccessMode=ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay=ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStructure);
	
	
	
	
	ADC_InitStructure.ADC_Resolution=ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConvEdge=ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion=1;
	ADC_Init(ADC3,&ADC_InitStructure);//ADC初始化配置。
	
//	ADC_RegularChannelConfig(ADC3,ADC_Channel_5,1,ADC_SampleTime_480Cycles);
	//ADC规则通道配置。
	
	
	
	ADC_Cmd(ADC3,ENABLE);//使能ADC3.
	
	
	
	
	





	

 }







u16 Get_Adc(u8 ch)//获取ADC的值。
 {
 
		ADC_RegularChannelConfig(ADC3,ch,1,ADC_SampleTime_480Cycles);
 
		ADC_SoftwareStartConv(ADC3);
	  while(!ADC_GetFlagStatus(ADC3,ADC_FLAG_EOC));
    return ADC_GetConversionValue(ADC3);
 
 }
 
 
 
 
 
 
u16 Get_Adc_Average(u8 ch, u8 times)//取均值。
 {
 u16 t=0;
 u16 m=times;
for(;times>0;times--)
	{
		t=t+Get_Adc(ch);
		delay_ms(20);
	}
return t/m;


}

