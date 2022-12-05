#include "stm32f10x.h"
#include "stdio.h"
#include "stdlib.h"
 void USART_IN(void)
{

	GPIO_InitTypeDef  GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); 
 	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;       
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	  	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;       
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	
	
	
	USART_InitStructure.USART_BaudRate=4800;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Parity= USART_Parity_No;
	
	 USART_Init(USART1,&USART_InitStructure);
	 USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	 USART_Cmd(USART1,ENABLE);
	 
	 
	
	
	 NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	 NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
	 NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
	 
	 NVIC_Init(&NVIC_InitStructure);
	
	 
	 
	 
	 
	 
	 
}

void USART1_IRQHandler(void)
	{
	 u8 R;
	 if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
	 {
	 
	 R=USART_ReceiveData( USART1);
	
	 USART_SendData(USART1,R);
	 
	 }
 
//USART_ClearITPendingBit(USART1,USART_IT_RXNE);

	}

		
	
	
	
	//�������´���,֧��printf����,������Ҫѡ��use MicroLIB   
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
 int handle; 

}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
void _sys_exit(int x) 
{ 
 x = x; 
} 
 
#endif 
	
	
	
//int fputc(int ch,FILE *f)
//{
// while(USART_GetITStatus(USART1,USART_FLAG_TC)==SET);
//	USART_SendData(USART1,(unsigned char)ch);
//	USART_ClearFlag(USART1,USART_FLAG_TC);
//	
//	
//	return(ch);
//	






//}
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{      
 while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
    USART1->DR = (u8) ch;      
 return ch;
}
	
