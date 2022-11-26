#include "sys.h"
#include "stm32f10x.h"
#include "delay.h"
void TIM3init(u16 arr,u16 psc)
{ 
	NVIC_InitTypeDef  NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructrue;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 ,ENABLE);
	
	TIM_TimeBaseInitStructrue.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructrue.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructrue.TIM_Period=arr;  
	TIM_TimeBaseInitStructrue.TIM_Prescaler=psc;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructrue);
	
	
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_Init(&NVIC_InitStructure);
	TIM_Cmd(TIM3,ENABLE);
	
}
void TIM3_IRQHandler(void)
{
	
	
if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
	
PAout(9)=!PAout(9);

TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

}
