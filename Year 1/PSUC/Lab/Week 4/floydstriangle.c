#include<stdio.h>
int main()
{
int i,j,n,k=1;
printf("Enter number of rows");
scanf("%d",&n);
for(i=0;i<n;i++)
 {
 printf("\n");
  for(j=0;j<=i;j++)
    {
    printf("%d \t  ",k);
    k++;
    }
  }
}
