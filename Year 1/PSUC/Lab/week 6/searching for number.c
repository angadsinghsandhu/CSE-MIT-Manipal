#include<stdio.h>
int main()
{
    int m,n,i,j,nn=0,num,a[10][10];
    printf("enter the rows and columns of the matrix\n");
    scanf("%d%d",&m,&n);
    printf("enter the elements of the matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter number to be searched\n");
    scanf("%d",&num);
     for(i=0;i<m;i++)
    {
        for(j=i;j<i+1;j++)
        {
           if(a[i][j]==num)
            nn++;
        }
    }
    printf("the searched number occurs %d time(s) in the matrix",nn);
    return 0;
}
