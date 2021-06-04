#include<lpc17XX.h>

unsigned int i,j;
unsignerd long LED = 0x00000010;

// using port 4 to 11 [1 pin 4 operations]
// [Pin0 for 0-15 is pin select 0, 16-31 is pin select 1]



int main(void){
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;  // making sure bits 9-24 are 0
    LPC_GPIO0->FIODIR |= 0x00000FF0;    // making sure bits 5-12 ar e 1
    
    SystemInit();
    SystemCoreClockUpdate();

    while(1){
        LED = 0x00000010;

        for(i=1; i<9; i++){
            LPC_GPIO0->FIOSET = LED;
            for(j=0; j<10000; j++);
            LED <<= 1;
        }

        LED = 0x00000010;

        for(i=1; i<9; i++){
            LPC_GPIO0->FIOCLR = LED;
            for(j=0; j<10000; j++);
            LED <<= 1;
        }
    }
}