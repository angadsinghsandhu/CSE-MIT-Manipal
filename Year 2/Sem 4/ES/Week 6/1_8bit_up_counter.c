// Q1
#include<lpc17xx.h>

unsigned int i,j, c=0;
unsigned long LED = 0x00000010;


int main(void){
		LPC_PINCON->PINSEL0 &= 0xFF0000FF;
		LPC_GPIO0->FIODIR |= 0x000000FF;
    
		SystemInit();
    SystemCoreClockUpdate();

    while(1){
        // LED = 0x00000010;
        for(i=1; i<256; i++){
            LPC_GPIO0->FIOPIN = c<<4;
            for(j=0; j<1000; j++);
            c++;
        }

    }
}