#include<stdio.h>
int main()
{
float x,t,sum;
int n,i;
printf("Enter value of x and no. of terms");
scanf("%d%f",&n,&x);
x=x*3.14159/180.0;
t=x;
sum=x;
for(i=1;i<=n;i++)
 {
 t=(t*(-1)*x*x)/(2*i*(2*i+1));
 sum+=t;

 }
  printf("%f\t",sum);
printf("Sin(%f)=%f",x,sum);
}
