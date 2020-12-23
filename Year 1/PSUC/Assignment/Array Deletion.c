#include<stdio.h>
int del(int x[],int *ptr)
{
    int i,j,n=*ptr,count=0;
    printf("\n%d\n",*ptr);
    for(i=n-1;i>=0;i--)
    {
        if (x[i]%2==0)
        {
            for(j=i;j<n-1;j++)
            {
                x[j]=x[j+1];
            }
            count++;
        }
    }
    *ptr = *ptr - count;
     printf("\n%d\n",*ptr);
}
int main()
{
    int x[100],i,j,len;
    printf("Enter Length of array :\n");
    scanf("%d",&len);
    printf("Enter array :\n");
    for(i=0;i<len;i++)
        scanf("%d",&x[i]);
    del(x,&len);
    printf("New array :\n");
    for(i=0;i<len;i++)
        printf("%d\t",x[i]);
    return 0;
}
