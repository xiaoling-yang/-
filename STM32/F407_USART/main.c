#include "stm32f4xx.h"
#include "usart.h"
#include "SYS.h"





void My_USART_INIT(void)
{ 
 NVIC_InitTypeDef  NVIC_InitStructure;
 USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef  GPIO_InitStructure;
	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
 
GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;
GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
 
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
 
 
USART_InitStructure.USART_BaudRate = 115200;
USART_InitStructure.USART_WordLength = USART_WordLength_8b;
USART_InitStructure.USART_StopBits = USART_StopBits_1; 
USART_InitStructure.USART_Parity = USART_Parity_No;
USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

USART_Init(USART1,&USART_InitStructure);
USART_Cmd(USART1,ENABLE);

USART_ITConfig(USART1,USART_IT_RXNE,ENABLE); 

NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1 ;
NVIC_Init(&NVIC_InitStructure);



}

void USART1_IRQHandler(void)
{

  u8 res;

 if(USART_GetITStatus(USART1,USART_IT_RXNE))
 {
  res=USART_ReceiveData(USART1);
  USART_SendData(USART1,res);
 
 }

}

int main(void)
{  My_USART_INIT(); 
	NVIC_PriorityGroupConfig (NVIC_PriorityGroup_2);
	


	
while(1);
}
