#include "sys.h"
#include "stm32f10x.h"
#include "delay.h"
//void TIM3init(u16 arr,u16 psc)
//{ 
//	NVIC_InitTypeDef  NVIC_InitStructure;
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructrue;
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 ,ENABLE);
//	
//	TIM_TimeBaseInitStructrue.TIM_CounterMode=TIM_CounterMode_Up;
//	TIM_TimeBaseInitStructrue.TIM_ClockDivision=TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructrue.TIM_Period=arr;  
//	TIM_TimeBaseInitStructrue.TIM_Prescaler=psc;
//	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructrue);
//	
//	
//	
//	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
//	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
//	NVIC_Init(&NVIC_InitStructure);
//	TIM_Cmd(TIM3,ENABLE);
//	
//}
//void TIM3_IRQHandler(void)
//{
//	
//	
//if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
//	
//PBout(5)=!PBout(5);

//TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

//}
void TIMER3_PWM(u16 arr,u16 psc)
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructrue;
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;       
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_TimeBaseInitStructrue.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructrue.TIM_ClockDivision=0;
	TIM_TimeBaseInitStructrue.TIM_Period=arr;  
	TIM_TimeBaseInitStructrue.TIM_Prescaler=psc;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructrue);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_Cmd(TIM3,ENABLE);
	
  
	
	
}

