#include<stdio.h>
void main()
{
    int a[30],*p,n,l,i;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements:\n\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    l=a[0];
    p=&a;
    for(i=0;i<n;++i)
    {
        if(*(p+i)>l)
            l=*(p+i);
    }
    printf("\nThe largest element is: %d",l);
}
