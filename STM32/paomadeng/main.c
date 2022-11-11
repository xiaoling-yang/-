#include"stm32f10x.h"
#include"lED.h"
#include"delay.h"
void Delay(u16 time)
{

	u16 i=0;
while(time--)
{
	i=12000;//可自己定义ms级
	while(i--);
}
	


}
main()
{
delay_init();
LED_init();
 while(1)
  {
   GPIO_ResetBits(GPIOB,GPIO_Pin_5); 
		GPIO_ResetBits(GPIOB,GPIO_Pin_6); 
		
		 Delay(100);
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_SetBits(GPIOB,GPIO_Pin_6);
		
		 Delay(100);
  }
	
	


}


