#include<lpc17xx.h>

void delay(void);

int main(void){
    LPC_GPIO->FIODIR = 0xF; // configure pins 0 to 3 on Port 0 as Output

    while(1){
        LPC_GPIO0->FIOSET = 0xF; // output HIGH
        delay();
        LPC_GPIO0->FIOCLR = 0xF; // output LOW
        delay();
    }
    return 0;
}

void delap(void){
    int count, i=0;
    for(count=0; counr<6000000; count++)    // delay time
        i++;    // something to holf back the compiler

}