#include<stdio.h>
int main()
{
int a[10],i,pos,n;
printf("Enter size");
scanf("%d",&n);
printf("Enter elements in Array");
for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
printf("Enter position");
scanf("%d",&pos);
for(i=pos;i<n;i++)
 {
 a[i-1]=a[i];
 n=n-1;
 }
printf("Array after deletion");
for(i=0;i<n-1;i++)
{
printf("%d",&a[i]);
}
}
