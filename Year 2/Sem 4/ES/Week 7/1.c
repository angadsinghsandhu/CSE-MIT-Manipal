// 1
//C Program to display 8-bit binary up counter on the LEDs.
#include<LPC17XX.h>
unsigned int dig_select[4] = {0,1,2,3};
unsigned int seg_select[4] = {0<<23, 1<<23, 2<<23, 3<<23};
unsigned int seven_seg[10] ={0x3F,0x06,0x5B,0x4F,0x66,0x60,0x7D,0x07,0x7F,0x6F};
unsigned int dig_value[4] = {1,2,3,4};
unsigned int dig_count=0;
unsigned int seg_count=0x00, temp1=0x00;

void delay(void);
void display(void);
int main()
{
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF;
    LPC_GPIO0->FIODIR = 0XFF<<4;
    LPC_GPIO1->FIODIR = 0XF<<23;
    while(1){
        delay();
        display();
        
        LPC_GPIO1->FIOPIN = dig_select[dig_count]<<23;
        LPC_GPIO0->FIOPIN = seven_seg[dig_value[dig_count]]<<4;
        dig_count+=1;
        
        if(dig_count == 4){
            dig_count = 0;
        }
    }
}

void display(void) //To Display on 7-segments
{
    unsigned int i;
    LPC_GPIO1->FIOPIN = seg_select[seg_count];
    if(seg_count == 0x00) // For Segment U8
    {
    temp1 = dig_count;
    } else if(seg_count == 0x01) // For Segment U9
    {
    temp1 = dig_count;
    } else if(seg_count == 0x02) // For Segment U10
    {
    temp1 = dig_count;
    } else if(seg_count == 0x03) // For Segment U11
    {
    temp1 = dig_count;
    }
    
    LPC_GPIO0->FIOPIN = seven_seg[temp1]<<4; // Taking Data Lines for 7-Seg
    for(i =0;i<500;i++);
}

void delay(void) {
    unsigned int i;
    for(i=0;i<10000;i++);
}

Explanation:
It can be seen that the tick marks in port 0 correspond to the value 00000110, which from the lookup table, tells us
that the value displayed on the seven-segment display is 1

Explanation:
It can be seen that the tick marks in port 0 correspond to the value 01011011, which from the lookup table tells us
that the value displayed on the seven-segment display is 2.
In both the above screenshots, segment U8 is enabled


