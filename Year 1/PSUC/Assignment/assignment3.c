#include<stdio.h>
void armstrong(int arr[10][10],int N,int M)
{
int sum,digit,num,i,j,x;
for(i=0;i<N;i++)
    for(j=0;j<M;j++)
    {
        sum=0;
        num=arr[i][j];
        x=arr[i][j];
        while(num!=0)
        {
        digit=num%10;
        num=num/10;
        sum=sum+digit*digit*digit;
        }
        if(sum!=arr[i][j])
            arr[i][j]=x*x;
        else
            arr[i][j]=x;
    }
}
int main()
{
int N,M,a[10][10],i,j;
printf("enter the number of rows and column of a matrix\n");
scanf("%d%d",&N,&M);
printf("enter elements of the matrix\n");
for(i=0;i<N;i++)
    for(j=0;j<M;j++)
        scanf("%d",&a[i][j]);
armstrong(a,N,M);
printf("the new matrix is :\n");
for(i=0;i<N;i++)
    {
    printf("\n");
    for(j=0;j<M;j++)
        printf("%d\t",a[i][j]);
    }
return 0;
}
