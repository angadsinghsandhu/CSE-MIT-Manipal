#include<stdio.h>
#include<math.h>
int main()
{
int num,digi,sum=0,a;
printf("enter 3 digit number");
scanf("%d",&num);

a=num;
while(num>0)
{
digi=num%10;
sum=sum+digi*digi*digi;
num=num/10;
}
if(a==sum)
{
printf("%d is an armstrong number",sum);
}
else
{
printf("%d is not an armstrong number",sum);
}
}
