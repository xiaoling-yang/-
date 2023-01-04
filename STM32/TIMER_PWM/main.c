#include "stm32f10x.h"
#include "TIMinit.h"
#include "EXinit.h"
#include "delay.h"
void Delay(u16 time)
{

	u16 i;
while(time--)
{
	i=1200;
	while(i--);
}
}

 void delay(unsigned int ms)
{
 int i,j;
 for(i=ms;i>0;i--)
 for(j=114;j>0;j--);

}
 int main(void)
 {	
	 u16 l=0;
	 u16 d=1;
	 delay_init();
	  ledinit();
//	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 TIMER3_PWM(799,0);
	
	 while(1)
	 {
		 
//	 l++;

//   if(l>200)
//	 {
//		l=0;
//	 }
	 TIM_SetCompare2(TIM3,50);
	 }
		 
	 
	
		 
			 
		  
 }

 
