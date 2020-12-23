#include<stdio.h>
int product(int x,int y)
{
    if(x<y)
    {
        return product(y,x);
    }
    else if(y!=0)
    {
        return (x+product(x,y-1));
    }
    else
    {
        return 0;
    }
}
void main()
{
    int a,b,result;
    printf("\nEnter two numbers: ");
    scanf("%d %d",&a,&b);
    result=product(a,b);
    printf("\nThe product of the two numbers is: %d",result);
}


