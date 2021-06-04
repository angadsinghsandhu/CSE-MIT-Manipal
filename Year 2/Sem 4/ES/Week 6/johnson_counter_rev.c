#include<lpc17xx.h>

unsigned int i,j;
unsigned long LED = 0x00000010;

LPC_PINCON->PINSEL0 &= 0xFF0000FF;
LPC_GPIO0->FIODIR |= 0x000000FF;

int main(void){
    SystemInit();
    SystemCoreClockUpdate();
    
    LED = 0x00000800;

    for(i=9; i>0; i--){
        LPC_GPIO0->FIOSET = LED;
        for(j=0; j<10000; j++);
        LED >>= 1;
    }

    LED = 0x00000800;

    for(i=9; i>0; i--){
        LPC_GPIO0->FIOSCLR = LED;
        for(j=0; j<10000; j++);
        LED >>= 1;
    }
}