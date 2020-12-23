#include<stdio.h>
int main()
{
    int m,n,i,j,c1,c2,r1,r2,temp,x,a[10][10],row,column;
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
    printf("what do you wnat to interchange?(2 for row/1 for column)\n");
    scanf("%d",&x);
    if(x==1)
    {
       printf("enter rows to be interchanged\n");
       scanf("%d%d",&r1,&r2);
       for(j=0;j<n;j++)
           {
                temp=a[r1][j];
                a[r1][j]=a[r2][j];
                a[r2][j]=temp;
           }
            printf("the new matrix is\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    }
    else if(x==2)
    {
       printf("enter columns to be interchanged\n");
       scanf("%d%d",&c1,&c2);
       for(j=0;j<m;j++)
           {
                temp=a[c1][j];
                a[c1][j]=a[c2][j];
                a[c2][j]=temp;
           }
            printf("the new matrix is\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    }
    return 0;
}

