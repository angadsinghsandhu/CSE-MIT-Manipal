// 2
#include <LPC17xx.h>
#include <stdio.h>

unsigned int seg_select[4] = {0<<23, 1<<23, 2<<23, 3<<23};
unsigned int dig1=0x09, dig2=0x09, dig3=0x09, dig4=0x09;
unsigned int seg_count=0x03, temp1=0x00;
unsigned char array_dec[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned long int i=0;
void delay(void);
void display(void);

int main(void)
{ 
	SystemInit();
	SystemCoreClockUpdate();

    // data and enable lines
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_PINCON->PINSEL3 &= 0xFFC03FFF;
	
    // outputs
    LPC_GPIO0->FIODIR |= 0x00000FF0;
	LPC_GPIO1->FIODIR |= 0x07800000; 
	
    while(1)
	{
		delay();
		display();
		seg_count -=1; 
		if(seg_count == 0x00)
		{ 
			display();
			seg_count = 0x03;
			dig1 -=1;
			if(dig1 == -1)
			{ 
				dig1 = 0x09;
				dig2 -=1;
				if(dig2 == -1)
				{
					dig2 = 0x09;
					dig3-=1;
					if(dig3 == -1)
					{
						dig3 = 0x09;
						dig4 -= 1;
						if(dig4 == -1)
						{
							dig4 = 0x09;
						}
					}
				}
			}
		}
	}
}

// Displaying 7-segments
void display(void) 
{
	LPC_GPIO1->FIOPIN = seg_select[seg_count]; 
	if(seg_count == 0x00) {
		temp1 = dig1;
	} else if(seg_count == 0x01) {
		temp1 = dig2;
	} else if(seg_count == 0x02) {
		temp1 = dig3; 
    } else if(seg_count == 0x03) {
		temp1 = dig4;
	}

	LPC_GPIO0->FIOPIN = array_dec[temp1]<<4;
	for(i=0;i<500;i++);//delay
}

void delay(void)
{ 
	unsigned int i;
	for(i=0;i<10000;i++);
}