//Q2
#include<lpc17xx.h>

unsigned int i,j, c=0;
unsigned long LED = 0x00000010;

int main(void){
		LPC_PINCON->PINSEL0 &= 0xFF0000FF;

		LPC_GPIO0->FIODIR |= 0x000000FF;	// LED Output 
	
    SystemInit();
    SystemCoreClockUpdate();

    while(1){
			if(LPC_GPIO2->FIOPIN & 1<<12){
			if(LPC_GPIO2->FIOPIN){
				LED = 0x00000000;
				while(LED <= 0x00000FF0){
					LPC_GPIO0->FIOPIN = LED;
					LED += 0x00000010;
					for(j=0; j<1000; j++);
				}
			} else {
					LED = 0x00000010;
					while(LED){
						LPC_GPIO0->FIOPIN = LED;
						LED -= 0x00000010;
						for(j=0; j<1000; j++);
					}
				}
			}
		}
}
