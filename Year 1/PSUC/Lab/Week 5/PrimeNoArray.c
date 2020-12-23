#include<stdio.h>
int main()
{
int a[10],n,j,prime=1,i;
printf("Enter no of elements");
scanf("%d",&n);
printf("Enter elements in Array");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
  {
  for( j=2;j<n;j++);
   {
   if((a[i]%j)==0)
    {
    prime=0;
    break;

  if(prime==1)
  printf("%d is a prime no",a[i]);
     }
    }
  }
}

