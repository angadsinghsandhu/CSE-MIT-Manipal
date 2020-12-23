#include<stdio.h>
int main()
{
    int a[100][100],b[100][100],c[100][100],i,j,k,m,n;
    printf("Enter Dimension");
    scanf("%d%d",&m,&n);
    printf("Enter elements of 1st matrix");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter elements of 2nd matrix");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&b[i][j]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            c[i][j]=c[i][j]+a[i][k]*b[k][j];
        }
    }
    printf("\n The product matrix is \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%d\t",c[i][j]);
        printf("\n");
    }
}


