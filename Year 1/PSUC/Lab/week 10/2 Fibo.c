#include<stdio.h>
int rfibo(int n)
{
	if (n <= 1)
       return n;
   	else
       return (rfibo(n-1) + rfibo(n-2));
}
void main()
{
    int x,i;
    printf("Enter a numbers ");
    scanf("%d",&x);
    printf("The Series is:");
    for(i=0;i<x;i++)
        printf("\t%d",rfibo(i));
}
