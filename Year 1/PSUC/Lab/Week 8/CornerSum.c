#include<stdio.h>
void input(int m,int n,int a[10][10])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
int sum2(int m,int n,int a[10][10])
{
    int sum;
    sum=a[0][0]+a[0][n-1]+a[m-1][0]+a[m-1][n-1];
    return sum;
}
int main()
{
    int sum1,m,n,a[100][100];
    printf("enter the number of rows and columns respectively\n");
    scanf("%d%d",&m,&n);
    printf("enter elements of the matrix\n");
    input(m,n,a);
    sum1=sum2(m,n,a);
    printf("%d",sum1);
    return 0;
}
