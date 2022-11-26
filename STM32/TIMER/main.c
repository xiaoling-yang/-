#include "stm32f10x.h"
#include "SYS.H"
#include "EXinit.h"
#include "TIMinit.h"
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
		TIM3init(1999,7199);
	
	 
	 
	  
	 while(1);
		 
			 
		  
 }

 
