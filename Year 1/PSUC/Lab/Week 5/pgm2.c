#include<stdio.h>
main()
{
    int n,a[100],i,j,p;
    printf ("enter the number of elements \n");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
         printf("array elements are \t");
        scanf("%d",&a[i]);

    }
    for (i=0;i<n;i++)
    {
        for(j=2;j<a[i];j++)
        {
            if(a[i]%j==0)
                {
                    p=1;
                }
            else
                p=0;
        }
        if(p==1)
        {
            printf("%d",a[i]);
        }
    }
}

