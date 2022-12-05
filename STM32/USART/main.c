#include "stm32f10x.h"
#include "stdio.h"
#include "USARTIN.h"
void Delay(u16 time)
{

	u16 i;
while(time--)
{
	i=1200;
	while(i--);
}
}


 int main(void)
 {	
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
USART_IN();
	 
	
	 
	  

	  
	 while(1)
	 {
	 Delay(100);
	 printf("0X10");
	 
	 }
		 
	 
	
		 
			 
		  
 }

 
