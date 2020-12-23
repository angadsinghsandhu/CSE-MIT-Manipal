#include<stdio.h>
int oddsquare(int num)
{
    if (num!=1)
        return num + oddsquare(num-1);
    else
        return 1;
}
int evenfact(int num)
{
    if (num!=1)
        return num*evenfact(num-1);
    else
        return 1;
}
void Arr(int m, int n, int X[][10])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if (X[i][j]%2==0)
                X[i][j] = evenfact(X[i][j]);
            else
                X[i][j] = oddsquare(X[i][j]);
        }
    }
}
int main()
{
    int r,c,i,j,X[10][10];
    printf("Enter Rows and Columns of matrix :\n");
    scanf("%d%d",&r,&c);
    printf("Enter Matrix :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&X[i][j]);
    }
    Arr(r,c,X);
    printf("New Matrix :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d\t",X[i][j]);
        printf("\n");
    }
}

