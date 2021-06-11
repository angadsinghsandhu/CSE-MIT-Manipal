#include<LPC17XX.h>

unsigned int dig1,dig2,dig3,dig4; //dig1 corresponds to display in U8..
unsigned int seg_select[4] = {0<<23,1<<23,2<<23,3<<23} ;//1<<23 corresponds to U8
unsigned int seg_count = 0x00 ;
unsigned int temp = 0x00;
unsigned int seven_seg[10] ={0x3F,0x06,0x5B,0x4F,0x66,0x60,0x7D,0x07,0x7F,0x6F};
unsigned int i ;

int digSet[2] = {0x00, 0x09};
int digCheck[2] = {0x0A, 0xffffffff};
int digAdd[2] = {1, -1};
int cond = 0;

void upcounterIntialize(void);
void downcounterIntialize(void);
void display(void); //Prototype for display function
void delay(void);//Prototype for delay Function

int main(){
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF;
    LPC_GPIO0->FIODIR = 0XFF<<4;
    LPC_GPIO1->FIODIR = 0XF<<23;
    LPC_PINCON->PINSEL4 &=0XFCFFFFFF;
    LPC_GPIO2->FIODIR &= 0XFFFFEFFF;

    if(LPC_GPIO2->FIOPIN & 1<<12) {
        upcounterIntialize();
    } else {
        downcounterIntialize();
    }

    while(1) {
        display();
        delay();
        if(LPC_GPIO2->FIOPIN & 1<<12) {
            cond = 0;
        }
        else {
            cond = 1;
        }

        seg_count +=1 ;
        
        if(seg_count == 0x04){
            seg_count = 0x00;
            dig1 += digAdd[cond];
            
            if(dig1 == digCheck[cond]){
                dig1 = digSet[cond];
                dig2 += digAdd[cond];
                
                if(dig2 == digCheck[cond]){
                    dig2 = digSet[cond];
                    dig3 += digAdd[cond];
                    
                    if(dig3 == digCheck[cond]){
                        dig2 = digSet[cond];
                        dig4 += digAdd[cond];
                    
                        if(dig4 == digCheck[cond]){
                            dig4 = digSet[cond];
                        }
                    }
                }
            }
        }
    }
}


void display(){
    LPC_GPIO1->FIOPIN = seg_select[seg_count];
    if(seg_count == 0x00) {
        temp = dig1;
    } if(seg_count == 0x01) {
        temp = dig2;
    } if(seg_count == 0x02) {
        temp = dig3;
    } if(seg_count == 0x03) {
        temp = dig4;
    }
    
    LPC_GPIO0->FIOPIN = seven_seg[temp]<<4;
    for(i=0;i<5000;i++);
}


void delay(){
    for(i=0;i<10000;i++);
}


void upcounterIntialize(){
    dig1=0x00;
    dig2=0x00;
    dig3=0x00;
    dig4=0x00;
}


void downcounterIntialize(){
    dig1=0x09;
    dig2=0x09;
    dig3=0x09;
    dig4=0x09;
}

