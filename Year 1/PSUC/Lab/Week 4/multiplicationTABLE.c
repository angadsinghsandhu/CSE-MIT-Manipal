#include<stdio.h>
int main()
{
int i,k,j,n,res;
printf("Enter values of k and n");
scanf("%d%d",&k,&n);
for(i=1;i<=n;i++)
 {
 for(j=1;j<=k ;j++)
  {
  res=i*j;
  printf("%d*%d=%d\t",j,i,res);
  }
  printf("\n");
  }
}
