#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,i=0,sum,sum1=0,num,n=0,x=0,y=0;
    printf("enter number\n");
    scanf("%d",&num);
    a=num;
    b=num;
    while(b>0)
    {
        x=b%10;
        b=b/10;
        n++;
    }
    while(a>0&&i<=n)
    {
        y=a%10;
        i++;
        a=a/10;
        sum1=sum1+y*pow(10,(n-i));
    }
    sum=sum1+num*pow(10,n)+1;
    printf("the new number is %d",sum);
    return 0;
}
