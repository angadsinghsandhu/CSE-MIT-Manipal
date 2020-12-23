#include<stdio.h>
int main()
{
 int a,b;
 printf("ENTER");
 scanf("%d%d",&a,&b);
 a=a+b;
 b=a-b;
 a=a-b;
printf("\n%d%d",a,b);
}
