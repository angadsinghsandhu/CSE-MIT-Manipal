#include<stdio.h>
void largest(int a[],int n)
{
    int large=a[0],i;
    for(i=0;i<n;i++)
    {
        if(large<a[i])
            large=a[i];
    }
    printf("the largest term is %d",large);
}
void scanfn(int n, int a[])
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
int main()
{
    int n,a[10];
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter each element\n");
    scanfn(n,a);
    largest(a,n);
    return 0;
}
