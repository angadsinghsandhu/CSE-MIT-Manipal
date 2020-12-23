#include<stdio.h>
int fact(long int num)
{
    long int i,fact=1;
    for(i=1;i<=num;i++)
    {
        fact=fact*i;
    }
    return fact;
}
int main()
{
    long int N,R,facto,x,y,z;
    printf("enter N and R to find NCR\n");
    scanf("%d%d",&N,&R);
    x=fact(N);
    y=fact(R);
    z=fact(N-R);
    printf("the value of factorial N and R is %d and %d\n",x,y);
    facto=x/y/z;
    printf("the value of NCR is %d\n",facto);
    return 0;
}
