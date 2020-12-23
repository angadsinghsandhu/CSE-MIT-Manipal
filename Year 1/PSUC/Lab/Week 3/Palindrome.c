#include<stdio.h>
int main()
{
int right_digit,num,sum,a;
printf("enter number to check it is a palindrone\n");
scanf("%d",&num);
a=num;
right_digit=0;
sum=0;
while(num>0)
{
right_digit=num%10;
sum=sum*10+right_digit;
num=num/10;
}
if(sum==a)
{
printf("the number %d is a palindrome",sum);
}
else
{
printf("the number %d is not a palindrome",sum);
}
}
