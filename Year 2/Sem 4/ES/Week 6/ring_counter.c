#include<lpc17XX.h>

unsigned int i,j;
unsigned long LED = 0x00000010;


int main(void){
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x000000FF;

    SystemInit();
    SystemCoreClockUpdate();

    while(1){
        LED = 0x00000010;
        for(i=0; i<9; i++){
            LPC_GPIO0->FIOSET = LED;
            for(j=0; j<1000; j++);
            LPC_GPIO0->FIOCLR = LED;
            LED <<= 1;
        }
    }
}