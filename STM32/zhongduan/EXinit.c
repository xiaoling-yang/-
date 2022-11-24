#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"





void ledinit()
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);     
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;       
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
  GPIO_Init(GPIOA, &GPIO_InitStructure);        
      
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOB, &GPIO_InitStructure);           
 

}
void EXinit()
 {
  
  NVIC_InitTypeDef NVIC_InitStructure ;
  EXTI_InitTypeDef EXTI_InitStructure ;


  
RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource2);
  
  
EXTI_InitStructure.EXTI_Line=EXTI_Line2; 
EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
EXTI_InitStructure.EXTI_LineCmd=ENABLE;
EXTI_Init(&EXTI_InitStructure);

 
NVIC_InitStructure.NVIC_IRQChannel=EXTI2_IRQn ;
NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
NVIC_Init(&NVIC_InitStructure);


}


 void EXTI2_IRQHandler()
 {
 delay_ms(10);
 if(PBin(2)==0)
 {
 PAout(9)=!PAout(9);
 
 }
 EXTI_ClearITPendingBit(EXTI_Line2);
 }


