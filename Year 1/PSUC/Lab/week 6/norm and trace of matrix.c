#include<stdio.h>
#include<math.h>
int main()
{
    int a[10][10],i,j,sum=0,trace=0,m,n,out;
    float norm;
    printf("enter rows and column of the matrix\n");
    scanf("%d%d",&m,&n);
    printf("enter the elements of the matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
     if(m==n)
    {
        out=1;
         for(i=0;i<m;i++)
        {
        trace+=a[i][i];
        }
    }
    else
        out=0;
   for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=(a[i][j])*(a[i][j]);
        }
    }
    printf("\n");
    norm=sqrt(sum);
    if(out==1)
        printf("the trace is %d\n",trace);
    else
        printf("the trace cannot be found\n");
    printf("the norm is %f\n",norm);
    return 0;
}
