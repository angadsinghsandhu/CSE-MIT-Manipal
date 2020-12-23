#include<stdio.h>
int prod(int m,int n)
{
    if (n==0)
        return 0;
    else
        return m + prod(m,n-1);
}
int main()
{
    int  m,n,x;
    scanf("%d%d",&m,&n);
    x=prod(m,n);
    printf("%d",x);
    return 0;
}
