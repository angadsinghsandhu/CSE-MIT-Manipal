#include<stdio.h>
#include<math.h>
int main()
{
    int num,a,sum=0,n,x,y;
    printf("enter number\n");
    scanf("%d",&num);
    a=num;
    while(a>0)
    {
        y=a%10;
        a=a/10;
        sum=sum*10+y;
    }
    while(sum>0)
    {
        x=sum%10;
        switch (x)
        {
            case 0:
            printf("zero\t");
            break;
            case 1:
            printf("one\t");
            break;
            case 2:
            printf("two\t");
            break;
            case 3:
            printf("three\t");
            break;
            case 4:
            printf("four\t");
            break;
            case 5:
            printf("five\t");
            break;
            case 6:
            printf("six\t");
            break;
            case 7:
            printf("seven\t");
            break;
            case 8:
            printf("eight\t");
            break;
            case 9:
            printf("nine\t");
            break;
        }
        sum=sum/10;
    }
    return 0;
}

