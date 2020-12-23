#include<stdio.h>
int main()
{
int a,b,c,smallest;
printf("enter 3 numbers");
scanf("%d%d%d",&a,&b,&c);
smallest=(a<b)?((a<c)?a:c):((b<c)?b:c);
printf("the smallest number is %d",smallest);
return 0;
}
