#include<stdio.h>
int main()
{
int i,n,x=0;
printf("Enter the number");
scanf("%d",&n);
for(i=1;i<n;i++)
 {
 if(n%i==0)
 x=x+i;
 }
if(n==x)
 printf("Perfect number");
else
printf("Not a perfect number");
}
