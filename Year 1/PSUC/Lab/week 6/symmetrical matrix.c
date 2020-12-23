#include<stdio.h>
int main()
{
int a[10][10],i,j,m,n,flag=1;
printf("enter number of rows and columns of array\n");
scanf("%d%d",&m,&n);
if(m==n)
{
    printf("enter the elements of the matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=a[j][i])
            {
                flag=0;
                break;
            }
        }
    }
    if(flag==1)
        printf("the matrix is symmetrical");
    else
        printf("the matrix is not symmetrical");
}
else
    printf("the matrix cannot be symmertical");
return 0;
}
