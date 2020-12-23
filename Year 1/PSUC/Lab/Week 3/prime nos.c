#include<stdio.h>
int main()
{
int num,j,lim_up,lim_down,i;
printf("enter upper and lower limits");
scanf("%d%d",&lim_up,&lim_down);
j=2;
while(num<=lim_up)
{
i=num%j;
j=j++;
if(i==0)
{
printf("%d\n",num);
}
}
return 0;
}
