#include<stdio.h>
int rev(int num)
{
    int sum = 0,digit,i;
    for(i=0;num!=0;i++)
    {
     digit = num%10;
     num = num/10;
     sum = sum*10 + digit;
    }
    return sum;
}
void Arr(int m, int n, int X[][10])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            X[i][j] = rev(X[i][j]);
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
