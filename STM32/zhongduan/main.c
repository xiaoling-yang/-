#include "stm32f10x.h"
#include "SYS.H"
#include "EXinit.h"
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
	 ledinit();
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
EXinit();
EXTI2_IRQHandler();	 
	
	 
	 
	  
	 while(1)
		 {	
			 Delay(200);
		 } 
 }

 
