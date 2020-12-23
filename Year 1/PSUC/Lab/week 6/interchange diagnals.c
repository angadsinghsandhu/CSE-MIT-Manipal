#include<stdio.h>
int main()
{
    int m,n,i,j,temp,a[10][10];
    printf("enter the rows and columns of the matrix\n");
    scanf("%d%d",&m,&n);
    printf("enter the elements of the matrix\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
     for(i=0;i<m;i++)
        for(j=i;j<i+1;j++)
        {
            temp=a[i][j];
            a[i][j]=a[i][n-j-1];
            a[i][n-j-1]=temp;
        }
    printf("the new matrix is\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    return 0;
}
