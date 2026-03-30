
#include <hc_sr05.h>
#include<stdio.h>


int main(void)
{
	init();
	usart_init();

	while(1){
		if(motion_flag)
		{
			usart_write_string(USART2,"\rMotion Detected\n\r");
			motion_flag=0;
		}
}
	return 0;
}
