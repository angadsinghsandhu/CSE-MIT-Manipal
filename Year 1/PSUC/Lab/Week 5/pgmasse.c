#include<stdio.h>
main ()
{
    int n,i,f;
    printf("enter the number u have to find factors \n");
    scanf("%d",&n);
    for (i=1;i<=9;i++)
    {
        if(n%i==0)
        {
            f=i;


        switch(f)
        {
            case 1:
                {
                   printf("one\n");
                    break;
                }


            case 2:
                {
                    printf("two\n");
                }break;

            case 3:
            {
                printf("three\n");
            }
            break;

            case 4:
            {
                printf("four\n");
            }
            break;

            case 5:
            {
                printf("five\n");
            }
            break;

            case 6:
            {
                printf("six\n");
            }
            break;
            case 7:
            {
                printf("seven\n");
            }
            break;

            case 8:
            {
                printf("eight\n");
            }
            break;

            case 9:
                {
                    printf("nine\n");
                }
        }
        }
    }
}
