//Q3
#include<lpc17XX.h>

unsigned int i,j,k;
unsigned long LED;

int main(void){
		LPC_PINCON->PINSEL0 &= 0xFF0000FF;
		LPC_GPIO0->FIODIR |= 0x000000FF;	// LED Output 
	
    SystemInit();
    SystemCoreClockUpdate();

    while(1){
				if(LPC_GPIO2->FIOPIN & 1<<13)
					k = 1;
				else
					k =0;
				
				LED = 0x00000010;
        for(i=0; i<9 && k!=0; i++){
            LPC_GPIO0->FIOSET = LED;
            for(j=0; j<5000; j++);
            LPC_GPIO0->FIOCLR = LED;
            LED <<= 1;
        }
    }
}
