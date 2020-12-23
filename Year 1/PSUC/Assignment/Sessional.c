#include<stdio.h>
void Sort(int m, int n, int X[][10])
{
    if(m == 1)
        return 0;
    int i,j,large = X[0][0],pos=0,temp;
    for(i=0;i<m;i++)
    {
        if(X[i][0]>large)
        {
            large = X[i][0];
            pos = i;
        }
    }
    for(j=0;j<n;j++)
    {
        temp = X[pos][j];
        X[pos][j] = X[m-1][j];
        X[m-1][j] = temp;
    }
    Sort(m-1,n,X);
}
int main()
{
    int r,c,X[10][10],i,j;
    printf("enter number of rows and columns\n");
    scanf("%d%d",&r,&c);
    printf("Enter Matrix\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&X[i][j]);
    }
    printf("sorting Row wise....\n");
    Sort(r,c,X);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d\t",X[i][j]);
        printf("\n");
    }
    return 0;
}
