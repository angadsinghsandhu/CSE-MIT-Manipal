#include<stdio.h>
main()
{

int a,b,c;

printf("Enter your number\n");
scanf("%d",&a);

for(b=1;b<=a && b<10;b++)
{
   if(a%b==0)
   {
     if (b==1)
     {
       printf("One\n");

     }
     else if(b==2)
     {
       printf("Two\n");

     }
     else if(b==3)
     {
       printf("Three\n");

     }
       else if(b==4)
     {
       printf("Four\n");

     }
       else if(b==5)
     {
       printf("Five\n");

     }
       else if(b==6)
     {
       printf("Six\n");

     }
       else if(b==7)
     {
       printf("Seven\n");

     }
       else if(b==8)
     {
       printf("Eight\n");

     }
       else if(b==9)
     {
       printf("Nine\n");
       break;
     }





   }



}







}

