#include<stdio.h>
main()
{
    int n,a[100],i,s,l;
    printf ("enter the number of elements \n");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
         printf("array elements are \t");
        scanf("%d",&a[i]);

    }
    s=a[0];

    for (i=0;i<n;i++)
        {
            if(s>a[i])
            {
                s=a[i];
            }


        }
        l=a[0];

        for (i=0;i<n;i++)
        {
            if(l<a[i])
            {
                l=a[i];
            }
        }
printf("largest %d\nsmallest%d\n",l,s);
}
